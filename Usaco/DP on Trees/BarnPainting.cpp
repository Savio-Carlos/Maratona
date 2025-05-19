#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAX = 2e5+7;
const int MOD = 1e9+7;

int arr[MAX], dp[MAX][4];
vector<vector<int>> graph;

void dfs(int v, int p){
    if (arr[v] != 0)dp[v][arr[v]] = 1;
    else {
        for (int i = 1; i <= 3; i++){
            dp[v][i] = 1;
        }
    }
    for(auto u : graph[v]){ 
        if(u==p)continue;
        dfs(u,v); 
        if(arr[u] != 0){
            dp[v][arr[u]] = 0;
        }
        dp[v][1] *= (dp[u][2] + dp[u][3]);
        dp[v][2] *= (dp[u][1] + dp[u][3]);
        dp[v][3] *= (dp[u][2] + dp[u][1]);
        dp[v][1] %= MOD;
        dp[v][2] %= MOD;
        dp[v][3] %= MOD;
    }
}

void setIO(string name = "") {
	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}
signed main(){
    winton;
    setIO("barnpainting");
    int n, m;
    cin >> n >> m;
    graph.resize(n+1);
    for (int i = 0; i < n-1; i++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        arr[a] = b;
        dp[a][b] = 1;
    }
    dfs(1,-1);
    // for (int j = 1; j <= n; j++){
    //     cout << arr[j] << " ";
    // }
    // cout << endl;
    // for (int i = 1; i <= 3; i++){
    //     for (int j = 1; j <= n; j++){
    //         cout << dp[j][i] << " ";
    //     }
    //     cout << endl;
    // }
    cout << (dp[1][1] + dp[1][2] + dp[1][3])%MOD << endl;
}