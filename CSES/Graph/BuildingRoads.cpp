#include <bits/stdc++.h>
using namespace std;
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long
#define ld long double
const int MAXS = 1e5;

vector<vector<int>> g;
vector<int> visited;

void dfs(int v, vector<int>& comp){
    visited[v] = 1;
    comp.push_back(v);
    for (auto u : g[v]){
        if (!visited[u]){
            dfs(u, comp);
        }
    }
}

signed main() {
    winton;
    int n, m;
    cin >> n >> m;
    g.resize(n);
    visited.resize(n);

    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        g[--a].push_back(--b);
        g[b].push_back(a);
    }
    vector<vector<int>> comp(n);
    for (int i = 0; i < n; i++){
        if (!visited[i]) dfs(i, comp[i]);
    }

    vector<int> first_elements;
    for (const auto& c : comp) {
        if (!c.empty()) {
            first_elements.push_back(c[0]);
        }
    }

    vector<pair<int,int>> ans;
    if (first_elements.size() > 1){
        for (int i = 1; i < first_elements.size(); i++){
            ans.push_back({first_elements[i-1], first_elements[i]});
        }
    }
    cout << ans.size() << endl;
    for (auto [a,b] : ans) cout << a+1 << " " << b+1 << endl;
}