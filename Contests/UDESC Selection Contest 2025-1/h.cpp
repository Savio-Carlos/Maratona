#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define debug(x) cout << #x << " = " << x << "\n";
const int MAX = 5e5+7;
const int INF = INT_MAX;

int n, subsum[MAX], arr[MAX], dp[MAX];
vector<vector<int>> graph;

void dfs(int v, int p){
    subsum[v] = arr[v];
    int cur = 0, sons = 0;
    for (auto u : graph[v]){
        if (u == p) continue;
        dfs(u,v);
        subsum[v] += subsum[u];//somar toda a subarvore
        if(dp[u]>0) sons+=dp[u];
    }
    dp[v] = max(subsum[v], sons);
}

signed main(){
    winton;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    graph.resize(n);
    for (int i = 1; i < n; i++){
        int a;
        cin >> a;
        a--;
        graph[a].push_back(i);
        graph[i].push_back(a);
    }
    dfs(0,-1);
    cout << dp[0] << endl;
    //for (int i = 0; i < n; i++)cout<<subsum[i]<<" " ;
    //for (int i = 0; i < n; i++)cout<<i<<" " ;cout<<endl;
    //for (int i = 0; i < n; i++)cout<<dp[i]<<" " ;
}