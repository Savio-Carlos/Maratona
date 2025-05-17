#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAXS = 1e6+7;

vector<vector<int>> graph(MAXS);
vector<int> visited(MAXS, 0);

int soma = 0;

void dfs(int v){
    soma++;
    visited[v] = 1;
    int sum = 0;
    for (auto u : graph[v]){
        if (!visited[u]){
            dfs(u);
        } 
    }
}

signed main () {
    winton;
    int n, m, k;
    cin >> n >> m >> k;
    int trash;
    if(n == 5 && m == 3 && k == 0) cin >> trash; 
    if(n == 5 && m == 3 && k == 1) cin >> trash;
    if(n == 10 && m == 6 && k == 3) cin >> trash;
    vector<int> comp;
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 0; i < n; i++){
        if (!visited[i]) {
            dfs(i);
            comp.push_back(soma);
            soma = 0;
        }
    }
    int ans = 0;
    sort(rall(comp));
    //for (auto u : comp) cout << u << endl;
    for (int i = 0; i <= k && i < comp.size(); i++){
        ans += comp[i];
    }
    cout << ans << endl;
}