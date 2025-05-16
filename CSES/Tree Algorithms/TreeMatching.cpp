#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAX = 2e5+14;

int dp[MAX][2]; 
vector<vector<int>> graph;

void dfs(int v, int p){
    for (auto u : graph[v]){
        if (u == p) continue;
        //cout<< "CONEXAO: " << v << " -> " << u << endl;
        dfs(u,v);
        dp[v][0] += max(dp[u][1], dp[u][0]);
    }
    for (auto u : graph[v]){
        if (u == p) continue;
        dp[v][1] = max(dp[v][1], dp[u][0] + 1 + dp[v][0] - max(dp[u][1], dp[u][0]));
    }
}

signed main(){
    winton;
    int n;
    cin >> n;
    graph.resize(n);
    for (int i = 1; i < n; i++){
        int a,b;
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    dfs(0,-1);
    for (int j = 0; j < n; j++){
        cout << j+1 << " ";
    }
    cout << endl;
    for (int i = 0; i < 2; i++){
        for (int j = 0; j <= MAX; j++){
            cout << dp[j][i] << " ";
        }
        cout << endl;
    }
    cout << max(dp[0][0],dp[0][1]) << endl;
}