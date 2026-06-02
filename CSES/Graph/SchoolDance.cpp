#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define int long long
#define ld long double
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL)

#define debug(x)  cerr << #x << ": " << x << endl
#define debugv(x) cerr << #x << ": "; for(auto i : x) cerr << i << " "; cerr << endl
#define debugp(x) cerr << #x << ": " << x.first << " " << x.second << endl

const int INF = 1e18;

struct Dinic {
    struct edge { 
        int to, cap, rev, flow;
        bool res; 
        edge(int to_, int cap_, int rev_, bool res_) : to(to_), cap(cap_), rev(rev_), flow(0), res(res_) {}
    };
    vector<vector<edge>> graph;
    vector<int> level, beg;
    int n;
    int fluxo;

    Dinic(int n) : n(n), graph(n), level(n), beg(n), fluxo(0) {}

    void add(int a, int b, int c) {
        graph[a].emplace_back(b, c, (int)graph[b].size(), false);
        graph[b].emplace_back(a, 0, (int)graph[a].size() - 1, true);
    }

    bool bfs(int s, int t) {
        fill(level.begin(), level.end(), -1);
        fill(beg.begin(), beg.end(), 0);
        level[s] = 0; 
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            int u = q.front(); 
            q.pop();
            for (auto &e : graph[u]){
                if (level[e.to] != -1 or (e.flow == e.cap)) continue;
                level[e.to] = level[u] + 1;
                q.push(e.to);
            }
                
        }
        return level[t] >= 0;
    }

    int dfs(int v, int t, int f = INF) {
        if (v == t or !f) return f;

        for (int &i = beg[v]; i < (int)graph[v].size(); i++) {
            auto &e = graph[v][i];
            if (level[e.to] != level[v] + 1) continue;

            int d = dfs(e.to, t, min(f, e.cap - e.flow));
            
            if (!d) continue; 
            e.flow += d;
            graph[e.to][e.rev].flow -= d;
            return d;
            }
        return 0;
    }

    int max_flow(int s, int t) {
        while (bfs(s, t)) {
            while (int f = dfs(s, t)) fluxo += f;
        }
        return fluxo;
    }

    vector<pair<int, int>> get_cut(int s, int t) {
        if (!fluxo) max_flow(s, t);
        vector<pair<int, int>> cut;
        vector<int> vis(graph.size(), 0), st = {s};
        vis[s] = 1;
        while (st.size()) {
            int u = st.back(); st.pop_back();
            for (auto e : graph[u]) if (!vis[e.to] and e.flow < e.cap){
                vis[e.to] = 1, st.push_back(e.to);
            }
        }
        for (int i = 0; i < graph.size(); i++) for (auto e : graph[i]){
            if (vis[i] and !vis[e.to] and !e.res) cut.emplace_back(i, e.to);
        }
        return cut;
    }

    //funcao para achar todos os caminhos de arestas disjuntas(cada aresta so aparece em um caminho)
    vector<vector<int>> get_paths(int s, int t){
        if(!fluxo) max_flow(s,t);

        
    }



};

signed main(){
    fastio;
    int n, m;
    cin >> n >> m;
    Dinic dinic(n);

    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        dinic.add(a, b, 1);
    }

    cout << dinic.max_flow(source, sink) << endl;


}