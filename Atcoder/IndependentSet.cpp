#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAX = 2e5+14;
const int MOD = 1e9+7;

int dp[MAX][2], teste[MAX];
vector<int> graph[MAX];

void dfs(int v, int p){
    dp[v][1]=1;
    dp[v][0]=1;
    for (auto u : graph[v]){
        if (u == p) continue;
        dfs(u,v);
        dp[v][0] = (dp[v][0] * (dp[u][1]+dp[u][0]))%MOD;
    }
        for (auto u : graph[v]){
        if (u == p) continue;
        dp[v][1] = (dp[v][1] * (dp[u][0]))%MOD; 
    }
}

signed main(){
    winton;
    int n;
    cin >> n;
    for (int i = 1; i < n; i++){
        int a,b;
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    dfs(0,-1);
    // for (int i = 0; i < n; i++){cout<<1+i<<" ";}
    // cout << endl;
    // for (int j = 0; j < 2; j++){
    //     for (int i = 0; i < n; i++){
    //     cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << (dp[0][1] + dp[0][0])%MOD << endl;
}