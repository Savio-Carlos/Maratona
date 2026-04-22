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

int arr[MAX], dp[MAX][2], ans = 0;
vector<vector<int>> graph;

void dfs(int v, int p){
    dp[v][arr[v]]++;
    for(auto u : graph[v]){ 
        if(u==p)continue;
        dfs(u,v);
        dp[v][0] += dp[u][0];
        dp[v][1] += dp[u][1]; 
    }
    if (dp[v][1] == dp[v][0]) ans++;
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--){ 
        int n;
        cin >> n;
        ans = 0;
        graph.resize(n+1);
        for(int i = 0; i <= n; i++){
            graph[i].clear();
            dp[i][0] = 0;
            dp[i][1] = 0;
            arr[i] = 0;
        }
        for (int i = 1; i < n; i++){
            int p;
            cin >> p;
            graph[i].push_back(--p);
            graph[p].push_back(i);
        }
        string s;
        cin >> s;
        for (int i = 0; i < n; i++){
            arr[i] = (s[i] =='W');
        }
        dfs(0,-1);
        // cout << endl;
        // for (int i = 0; i < 2; i++){
        //     for (int j = 0; j < n; j++){
        //         cout << dp[j][i] << " ";
        //     }
        //     cout << endl;
        // }
        cout << ans << endl;
    }
}