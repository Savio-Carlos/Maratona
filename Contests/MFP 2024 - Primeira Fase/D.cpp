#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAXN = 1e6+7;
const int INF = -4e18;

int n, k;
vector<int> x;
vector<vector<int>> graph;
vector<int> sz;
vector<vector<int>> dp;

void dfs(int u) {
    sz[u] = 1;
    vector<int> f(1, 0);
    for (int v : graph[u]) {
        dfs(v);
        int sz1 = min(k, (int)f.size() - 1);
        int sz2 = min(k, sz[v]);
        vector<int> novo(min(k, sz1 + sz2) + 1, INF);
        for (int i = 0; i <= sz1; i++) 
        if (f[i] > INF/2) {
            for (int j = 0; j <= sz2; j++) {
                if (dp[v][j] > INF/2) {
                    int nj = i + j;
                    if (nj <= k) novo[nj] = max(novo[nj], f[i] + dp[v][j]);
                }
            }
        }
        f.swap(novo);
        sz[u] += sz[v];
    }

    int m = min(k, sz[u]);
    dp[u].assign(m+1, INF);
    for (int s = 0; s < (int)f.size(); s++){
        dp[u][s] = f[s];
    }
       
    if (u != 1 && m >= 1){
        dp[u][1] = max(dp[u][1], x[u]);
    }
        
}

signed main(){
    winton;
    cin >> n >> k;
    x.assign(n+1, 0);
    for (int i = 2; i <= n; i++){
        cin >> x[i];

    }
    graph.assign(n+1, {});
    for (int i = 2, p; i <= n; i++){
        cin >> p;
        graph[p].push_back(i);
    }

    dp.resize(n+1);
    sz.assign(n+1, 0);
    dfs(1);
    int ans = (k < dp[1].size() ? dp[1][k] : INF);
    cout << max(0LL, ans) << endl;
}