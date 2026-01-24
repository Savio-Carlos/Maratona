#include <bits/stdc++.h>
using namespace std;

#define int long long
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)

const int INF = 1e18;

signed main() {
    winton;
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    vector<vector<int>> dist(n + 1, vector<int>(2, INF));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

    dist[1][0] = 0;
    pq.push({0, 1, 0});

    while (!pq.empty()) {
        auto [d, u, uu] = pq.top();
        pq.pop();

        if (d > dist[u][uu]) continue;

        for (auto [v, w] : graph[u]) {
            if (dist[u][uu] + w < dist[v][uu]) {
                dist[v][uu] = dist[u][uu] + w;
                pq.push({dist[v][uu], v, uu});
            }
            if (!uu) {
                int c2 = w / 2;
                if (dist[u][0] + c2 < dist[v][1]) {
                    dist[v][1] = dist[u][0] + c2;
                    pq.push({dist[v][1], v, 1});
                }
            }
        }
    }

    cout << dist[n][1] << endl;
}
