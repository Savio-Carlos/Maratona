//Template
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
    struct Edge { 
        int to, cap, rev; 
    };
    vector<vector<Edge>> graph;
    vector<int> level, beg;
    int n;

    Dinic(int n) : n(n), graph(n), level(n), beg(n) {}

    void add(int a, int b, int c) {
        graph[a].push_back({b, c, graph[b].size()});
        graph[b].push_back({a, 0, graph[a].size() - 1});
    }

    bool bfs(int s, int t) {
        fill(level.begin(), level.end(), -1);
        queue<int> q;
        level[s] = 0; q.push(s);
        while (!q.empty()) {
            int u = q.front(); 
            q.pop();
            for (auto &e : graph[u])
                if (e.cap > 0 && level[e.to] < 0) {
                    level[e.to] = level[u] + 1;
                    q.push(e.to);
                }
        }
        return level[t] >= 0;
    }

    int dfs(int v, int t, int f) {
        if (v == t) return f;

        for (int &i = beg[v]; i < graph[v].size(); i++) {
            Edge &e = graph[v][i];
            if (e.cap > 0 && level[v] < level[e.to]) {
                int d = dfs(e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    graph[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    int max_flow(int s, int t) {
        int flow = 0;
        while (bfs(s, t)) {
            fill(beg.begin(), beg.end(), 0);
            int f;
            while ((f = dfs(s, t, INF)) > 0) flow += f;
        }
        return flow;
    }
};

signed main(){
    fastio;
    int n, m;
    cin >> n >> m;
    Dinic dinic(n+2);
    for (int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        dinic.add(a, b, c);
    }
    int ans = dinic.max_flow(1, n);
    cout << ans << endl;
}