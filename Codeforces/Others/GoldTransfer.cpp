#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAXN = 1e6+7;
const int LOG = 20;
const int INF = INT_MAX;

int n, depth[MAXN], ancestor[MAXN][LOG+1], visited[MAXN];
vector<vector<int>> graph(MAXN);
vector<pair<int,int>> gold(MAXN);//first = amount(a), second = cost(c)


int lca(int v){
    for(int i = LOG; i >= 0; i--){
        if (gold[ancestor[v][i]].first > 0){
            v = ancestor[v][i];
        }
    }
    return v;
}

pair<int,int> solve(int v, int w){
    int bought = 0, cost = 0;
    while (w != 0){
        int best = lca(v);
        if (best == v && gold[v].first == 0) return {bought,cost};

        int mn = min(gold[best].first, w);
        bought += mn;
        cost += mn*gold[best].second;
        w-=mn;
        gold[best].first-=mn;
    }
    return {bought,cost};
}

signed main(){
    winton;
    int a0, c0;
    cin >> n >> a0 >> c0;
    gold[0].first = a0;
    gold[0].second = c0;
    for(int i = 1; i <= n; i++){
        int q;
        cin >> q;
        if (q == 1){
            int p, a, c;
            cin >> p >> a >> c;
            gold[i].first = a;
            gold[i].second = c;
            ancestor[i][0] = p;
            for (int j = 1; j <= LOG; j++){
                ancestor[i][j] = ancestor[ancestor[i][j-1]][j-1];
            }
        }
        else {
            int v, w;
            cin >> v >> w;
            pair<int,int> ans = solve(v,w);
            cout << ans.first << " " << ans.second << endl;
        }
    }
}