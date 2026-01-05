#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

const int MAX = 1e5+7;

int n, com;
vector<int> g[MAX], gi[MAX], g_scc[MAX];
int visited[MAX];
stack<int> S;
int comp[MAX];
ld not_fail[MAX];
ld scc_not_fail[MAX];
set<int> who[MAX];
int indeg[MAX];

void dfs(int k){
    visited[k] = 1;
    for (int i = 0; i < g[k].size(); i++){
        if (!visited[g[k][i]]) dfs(g[k][i]);
    }
    S.push(k);
}

void scc(int k, int c){
    visited[k] = 1;
    comp[k] = c;
    who[c].insert(k);
    for (int i = 0; i < gi[k].size(); i++){
        if (!visited[gi[k][i]]) scc(gi[k][i], c);
    }
}

void kosaraju(){
    for (int i = 0; i < n; i++) visited[i] = 0;
    for (int i = 0; i < n; i++) if(!visited[i]) dfs(i);
    for (int i = 0; i < n; i++) visited[i] = 0;

    while(S.size()){
        int u = S.top();
        S.pop();
        if(!visited[u]){
            com++;
            scc(u,com);
        }
    }
}

void build(){
    for(int u = 0; u < n; u++){
        scc_not_fail[comp[u]] = not_fail[u];
        for(int v : g[u]){
            if(comp[u] != comp[v]){
                g_scc[comp[v]].push_back(comp[u]);
            }
        }
    }
    for(int i = 1; i <= com; i++){
        sort(g_scc[i].begin(), g_scc[i].end());
        if (g_scc[i].empty())continue;
        g_scc[i].erase(unique(g_scc[i].begin(), g_scc[i].end()), g_scc[i].end());
    }
}

void solve(){
    for(int i = 1; i <= com; i++){
        ld p = 1;
        for (auto u : who[i]){
            p *= (not_fail[u]);
        }
        scc_not_fail[i] = p;
        
        for (auto u : g_scc[i]){
            indeg[u]++;
        }
    }

    ld mn = 1.0;
    for (int i = 1; i <= com; i++){
        // cout << "i: " << i << " sccnot_fail: "<< scc_not_fail[i] << endl;
        if (!indeg[i]) mn = min(mn, scc_not_fail[i]);
    }

    cout << fixed << setprecision(15) << mn << endl;
    

}

signed main(){
    fastio;
    int m;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        ld x;
        cin >> x;
        not_fail[i] = 1.0 - x;
    }
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        g[--a].push_back(--b);
        gi[b].push_back(a);
    }

    kosaraju();
    build();
    solve();
}