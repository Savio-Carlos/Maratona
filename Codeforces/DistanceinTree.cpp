#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAX = 5e4+7;

int n, k, ans = 0,dp[MAX][507], depth[MAX];
vector<vector<int>> graph;

void dfs(int v, int p){
    dp[v][0] = 1;
    for (auto u : graph[v]){
        if (u==p) continue;
        dfs(u,v);
        for (int i = 0; i <= k ; i++){
            ans += dp[u][i] * dp[v][k-i-1];
        }
        for (int i = 0; i <= k ; i++){
            dp[v][i+1] += dp[u][i];
        }
    }
}

signed main() {
    winton;
    cin >> n >> k;
    graph.resize(n);
    for (int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    dfs(0,-1);
    // for (int i = 0; i < 5; i++){
    //     for (int j = 0; j < 5; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << ans << endl;
}
