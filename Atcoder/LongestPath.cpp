#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAXN = 1e5+7;
const int MOD = 1e9+7;

int dp[MAXN], grau[MAXN];
vector<vector<int>> graph;

signed main(){
    winton;
    int n, m;
    cin >> n >> m;
    graph.resize(n+1);
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        grau[b]++;
        graph[a].push_back(b);
    }
    priority_queue<int> pq;
    for (int i = 1; i <= n; i++){
        if (grau[i] == 0) pq.push(i);
    }

    while(!pq.empty()){
        int v = pq.top();
        pq.pop();
        for (auto u : graph[v]){
            dp[u] = max(dp[u], dp[v]+1);
            grau[u]--;
            if (grau[u] == 0) pq.push(u);
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++){
        //cout << dp[i] << " ";
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
}
/*
    for (int i = 1; i <= n; i++){
        for (auto u : graph[i]){
            dp[u] = max(dp[u], dp[i] + 1);
        }
    }
*/