#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAX = 2e5+7;
const int INF = INT_MAX;

int n, dp[MAX][2], arr[MAX];
vector<vector<int>> graph;

void dfs(int v, int p){
    
    for (auto u : graph[v]){
        if (u == p) continue;
        dp[u][0] = min(arr[u], arr[u]-dp[v][1]);
        dp[u][1] = max(arr[u], arr[u]-dp[v][0]);
        dfs(u,v);
    }
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        graph.resize(n);
        for (int i = 0; i < n; i++){
            graph[i].clear();
            dp[i][0] = dp[i][1] = arr[i] = 0;
        }
        for (int i = 0; i < n; i++){
            cin >> arr[i];
        }
        for (int i = 0; i < n-1; i++){
            int a,b;
            cin >> a >> b;
            graph[--a].push_back(--b);
            graph[b].push_back(a);
        }
        dp[0][0] = dp[0][1] = arr[0];
        dfs(0,-1);
        for (int i = 0; i < n; i++){
            cout << dp[i][1] << " ";
        }
        cout << endl;
    }
}