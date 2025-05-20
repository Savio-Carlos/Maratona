#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAX = 1e6+7;
const int INF = -4e18;

int n, k, timer = 0, dp[MAX][2], arr[MAX], tin[MAX], tout[MAX];
vector<vector<int>> graph;
vector<int> euler;

void dfs(int v, int p) {
    tin[v] = ++timer;
    euler.push_back(arr[v]);
    for (int u : graph[v]) {
        if (u == p) continue;
        dfs(u,v);
    }
    tout[v] = timer;
}

signed main(){
    winton;
    cin >> n >> k;
    for (int i = 2; i <= n; i++){
        cin >> arr[i];
    }
    graph.assign(n+1, {});
    for (int i = 2; i <= n; i++){
        int a;
        cin >> a;
        graph[a].push_back(i);
        graph[i].push_back(a);
    }
    dfs(1, -1);
    for (int i = n; i >= 0; i--){
        dp[i][1] = max(dp[i][1], dp[tout[i]+1][0] + euler[i]);
        dp[i][0] = max(dp[i+1][0], dp[tout[i] + 1][1]);
    }
            for (int i = 0; i < 2; i++){
            for (int j = 0; j < n; j++){
                cout << dp[j][i] << " ";
            }
            cout << endl;
        }
    cout << max(dp[1][0], dp[1][1]) << endl;
}