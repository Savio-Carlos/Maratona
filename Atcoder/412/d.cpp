#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
const int MAX = 30+7;
const int MOD = 1e9+7;
const int INF = LLONG_MAX;

map<int, pair<int,int>> con;

signed main(){
    winton;
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> edges;
    int cnt = 0;
    map<pair<int, int>, int> edge_to_idx;
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            edges.push_back({i,j});
            edge_to_idx[{i,j}] = cnt++;
        }    
    }
    int e = edges.size();
    int startmask = 0;
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        --a; --b;
        if(a > b) swap(a,b);
        if (edge_to_idx.count({a,b})) {
            startmask |= (1 << edge_to_idx[{a,b}]);
        }
    }
    int ans = INF;
    for (int i = 0; i < (1<<e); i++){
        vector<int> deg(n,0);
        bool pos = true;
        for (int j = 0; j < e; j++){
            int idx = (1<<j);
            if (i & idx){
                auto [u,v] = edges[j];
                if (++deg[u] > 2 || ++deg[v] > 2){
                    pos = false;
                    break;
                }
            }
        }
        for (int i = 0; i < n; i++){
            if (deg[i]!=2) pos = false;
        }

        if (pos){
            int diff = startmask^i;
            int cnt = __builtin_popcount(diff);
            ans = min(ans,cnt);
            //debug(startmask);
            //debug(i);
        }
    }
    cout << ans << endl;
}


