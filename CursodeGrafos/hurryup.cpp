#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXS = 2000;
const int INF = 1e9+7;

double distance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

// Edge structure for the graph
struct Edge {
    int to, rev;
    double capacity, cost;
};

class MinCostMaxFlow {
public:
    MinCostMaxFlow(int n) : n(n), graph(n), potential(n), dist(n), parent(n), parentEdge(n) {}

    void addEdge(int from, int to, double capacity, double cost) {
        graph[from].push_back({to, (int)graph[to].size(), capacity, cost});
        graph[to].push_back({from, (int)graph[from].size() - 1, 0, -cost});
    }

    double minCostMaxFlow(int source, int sink, int flowRequired) {
        double totalFlow = 0, totalCost = 0;
        while (totalFlow < flowRequired) {
            // Shortest path from source to sink using potentials
            if (!shortestPath(source, sink)) break;

            // Find the maximum flow we can send along the path
            double flow = flowRequired - totalFlow;
            for (int v = sink; v != source; v = parent[v]) {
                int u = parent[v], e = parentEdge[v];
                flow = min(flow, graph[u][e].capacity);
            }

            // Update capacities and compute cost
            for (int v = sink; v != source; v = parent[v]) {
                int u = parent[v], e = parentEdge[v];
                graph[u][e].capacity -= flow;
                graph[v][graph[u][e].rev].capacity += flow;
                totalCost += flow * graph[u][e].cost;
            }

            totalFlow += flow;
        }

        return totalCost;
    }

private:
    int n;
    vector<vector<Edge>> graph;
    vector<double> potential, dist;
    vector<int> parent, parentEdge;

    bool shortestPath(int source, int sink) {
        fill(dist.begin(), dist.end(), INF);
        dist[source] = 0;

        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<>> pq;
        pq.push({0, source});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d != dist[u]) continue;

            for (int i = 0; i < (int)graph[u].size(); ++i) {
                Edge& e = graph[u][i];
                if (e.capacity > 0) {
                    double newDist = dist[u] + e.cost + potential[u] - potential[e.to];
                    if (newDist < dist[e.to]) {
                        dist[e.to] = newDist;
                        parent[e.to] = u;
                        parentEdge[e.to] = i;
                        pq.push({newDist, e.to});
                    }
                }
            }
        }

        for (int i = 0; i < n; ++i)
            if (dist[i] < INF) potential[i] += dist[i];

        return dist[sink] < INF;
    }
};

int main() {
    int N, M;
    while (cin >> N >> M, N || M) {
        vector<tuple<int, int, double>> players(N);
        vector<tuple<int, int, vector<int>>> points(M);

        for (int i = 0; i < N; ++i) {
            int x, y;
            double speed;
            cin >> x >> y >> speed;
            players[i] = {x, y, speed};
        }

        for (int j = 0; j < M; ++j) {
            int x, y, color;
            cin >> x >> y;
            vector<int> accepted;
            while (cin >> color, color != 0) {
                accepted.push_back(color - 1);
            }
            points[j] = {x, y, accepted};
        }

        //grafo
        int source = N + M, sink = source + 1;
        MinCostMaxFlow mcmf(N + M + 2);

        for (int i = 0; i < N; ++i) {
            mcmf.addEdge(source, i, 1, 0);
        }

        for (int i = 0; i < N; ++i) {
            auto [px, py, speed] = players[i];
            for (int j = 0; j < M; ++j) {
                auto [fx, fy, accepted] = points[j];
                if (find(accepted.begin(), accepted.end(), i) != accepted.end()) {
                    double time = distance(px, py, fx, fy) / speed;
                    mcmf.addEdge(i, N + j, 1, time);
                }
            }
        }
        for (int j = 0; j < M; ++j) {
            mcmf.addEdge(N + j, sink, 1, 0);
        }
        double result = mcmf.minCostMaxFlow(source, sink, N);
        cout << fixed << setprecision(1) << result << endl;
    }

    return 0;
}