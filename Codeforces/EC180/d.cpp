#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define debug(x) cout << #x << " = " << x << "\n";
const int MAX = 2e5+7;
const int INF = LLONG_MAX;

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> graph(n);
    for(int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    int centro = -1;
    for(int v = 0; v < n; v++){
        if(graph[v].size() == 2){
            centro = v;
            break;
        }
    }
    if(centro == -1){
        cout << "NO" << endl;
        return;
    }

    int u = graph[centro][0], w = graph[centro][1];
    bool pos = true;
    for(int v = 0; v < n; v++){
        if(v==u || v==centro || v==w) continue;
        if(graph[v].size() != 1){
            pos = false;
            break;
        }
    }
    if(!pos){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    vector<pair<int,int>> ans;
    ans.push_back({u, centro});
    ans.push_back({centro, w});
    for(int x : graph[u]){
        if(x == centro) continue;
        ans.push_back({u, x});
    }
    for(int x : graph[w]){
        if(x == centro) continue;
        ans.push_back({x, w});
    }
    for(auto &u : ans){
        cout << u.first+1 << " " << u.second+1 << endl;
    }
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}