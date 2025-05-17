#include <bits/stdc++.h>
using namespace std;
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long
#define ld long double
const int INF = 1e9+7;

class MaxFlow {
private:
    int n;
    vector<vector<int>> graph;
    vector<int> parent;
    bool bfs(int source, int sink) {
        fill(parent.begin(), parent.end(), -1);
        parent[source] = -2;

        queue<int> q;
        q.push(source);

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            for (int i = 0; i < n; i++) {
                if (parent[i] == -1 && graph[curr][i] > 0){
                    parent[i] = curr;
                    if (i == sink) return true;
                    q.push(i);
                }
            }
        }
        return false;
    }
public:
    MaxFlow(int n) : n(n), graph(n, vector<int>(n,0)), parent(n){}

    void addEdge(int from, int to, double capacity) {
        graph[from][to] = capacity;
    }

    double maxFlow(int source, int sink) {
        double flow = 0;
        while (bfs(source,sink)) {
            int path_flow = INT_MAX;

            for (int v = sink; v != source; v = parent[v]) {
                int u = parent[v];
                path_flow = min(path_flow, graph[u][v]);
            }

            for (int v = sink; v != source; v = parent[v]) {
                int u = parent[v];
                graph[u][v] -= path_flow;
                graph[v][u] += path_flow;
            }
            flow+=path_flow;
        }
        return flow;
    }
};

signed main() {
    winton
    int n, s, e, m; cin >> n >> s >> e;

    vector<int> st(s), en(e);
    for (int &i : st) cin >> i;
    for (int &i : en) cin >> i;

    cin >> m;

    int nodes = 2*n + 2, source = 0, sink = 2*n + 1;
    MaxFlow flow(nodes);

    for (int s : st) flow.addEdge(source,s,1);
    for (int e : en) flow.addEdge(e + n,sink,1);
    for (int i = 1; i <= n; i++) {
        flow.addEdge(i, i+n, 1);
    }

    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        flow.addEdge(a+n,b, 1);
    }

    int ans = flow.maxFlow(source,sink);
    cout << ans << endl;
}