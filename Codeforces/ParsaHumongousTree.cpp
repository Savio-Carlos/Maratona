#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAX = 2e5+7;
/*
dp[0] eu peguei o cara minimo(l)
dp[1] eu peguei o cara maximo(r)
*/
int n, dp[MAX][2], l[MAX], r[MAX];
vector<vector<int>> graph;


void dfs(int v, int p){
    for (auto u : graph[v]){
        if (u==p) continue;
        dfs(u,v);
        dp[v][0] += max(abs(l[v]-r[u]) + dp[u][1], abs(l[v]-l[u]) + dp[u][0]);
        dp[v][1] += max(abs(r[v]-r[u]) + dp[u][1], abs(r[v]-l[u]) + dp[u][0]);
    }
}

signed main() {
    winton;
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        graph.resize(n);
        for (int i = 0; i < n; i++){
            l[i] = r[i] = dp[i][0] = dp[i][1] = 0;
            graph[i].clear();
        }
        for (int i = 0; i < n; i++){
            cin >> l[i] >> r[i];
        }
        for (int i = 0; i < n-1; i++){
            int a, b;
            cin >> a >> b;
            graph[--a].push_back(--b);
            graph[b].push_back(a);
        }

        dfs(0,-1);
        // for (int i = 0; i < 2; i++){
        //     for (int j = 0; j < n; j++){
        //         cout << dp[j][i] << " ";
        //     }
        //     cout << endl;
        // }
        cout << max(dp[0][0], dp[0][1]) << endl;
    }
}
