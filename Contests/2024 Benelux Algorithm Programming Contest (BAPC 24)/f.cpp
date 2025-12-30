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
ld fail[MAX];
ld scc_fail[MAX];
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
        scc_fail[comp[u]] = fail[comp[u]];
        for(int v : g[u]){
            if(comp[u] != comp[v]){
                g_scc[comp[u]].push_back(comp[v]);
            }
        }
    }
    for(int i = 1; i <= com; i++){
        sort(g_scc[i].begin(), g_scc[i].end());
        if (g_scc[i].empty())continue;
        g_scc[i].erase(unique(g_scc[i].begin(), g_scc[i].end()));
    }
}

void solve(){
    for(int i = 1; i <= com; i++){
        ld p = 1;
        for (auto u : who[i]){
            p *= (1.0 - fail[u]);
        }
        scc_fail[i] = 1.0 - p;
        
        for (auto u : g_scc[i]){
            indeg[u]++;
        }
    }
    queue<int> q;
    for (int i = 1; i <= com; i++){
        if(indeg[i] == 0) q.push(i);
    }
    while(q.size()){
        int cur = q.front();
        q.pop();
        for(auto u : g_scc[cur]){
            // cout << "cur u:" << cur << " " << u << endl;
            indeg[u]--;
            if (indeg[u] == 0) q.push(u);
            scc_fail[u] = scc_fail[cur] + ((1.0 - scc_fail[cur]) * scc_fail[u]);
        }
    }
    ld mn = 1.0;
    for (int i = 1; i <= com; i++){
        // cout << "i: " << i << " sccfail: "<< scc_fail[i] << endl;
        mn = min(mn, scc_fail[i]);
    }

    cout << fixed << setprecision(15) << mn << endl;
    

}

signed main(){
    fastio;
    int m;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> fail[i];
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
     cout << "com: " << com << endl;
    for (int i = 1; i <= com; i++){
        cout << "i: " << i << endl;
        for (int u = 0; u < g_scc[i].size(); u++){
            cout << g_scc[i][u] << endl;
        }
    }

}