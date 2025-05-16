#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAX = 2e5+14;

int ans[MAX]; 
vector<vector<int>> graph;

int dfs(int v, int p){
    int cur = 0;
    for (auto u : graph[v]){
        if (u == p) continue;
        cur += dfs(u,v);
    }
    ans[v] = cur;
    return cur + 1;
}
signed main() {
    winton;
    int n;
    cin >> n;
    graph.resize(n);
    for (int i = 1; i < n; i++){
        int a;
        cin >> a;
        graph[--a].push_back(i);
        graph[i].push_back(a);
    }
    dfs(0,-1);
    for (int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }
}
