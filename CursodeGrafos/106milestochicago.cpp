#include <bits/stdc++.h>
using namespace std;
#define ll long long

double dijkstra(int n, vector<vector<pair<int,double>>>& ruas) {
    vector<double> d(n + 1, numeric_limits<double>::max());
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<>> pq;
    
    d[1] = 0.0;
    pq.emplace(0.0, 1);

    while (!pq.empty()) {
        pair<int,int> start = pq.top();
        int dist = start.first;
        int u = start.second;
        pq.pop();
        
        if (dist > d[u]) continue;

        for (auto& aresta : ruas[u]) {
            int v = aresta.first;
            double peso = aresta.second;
            
            if (d[u] + peso < d[v]) {
                d[v] = d[u] + peso;
                pq.emplace(d[v], v);
            }
        }
    }
    return exp(-d[n]) * 100.0;
}

int main() {
    int n, m;
    while (cin >> n >> m, n != 0) {
        vector<vector<pair<int,double>>> ruas(n + 1);

        for (int i = 0; i < m; ++i) {
            int a, b, p;
            cin >> a >> b >> p;
            double peso = -log(p / 100.0);
            ruas[a].emplace_back(b, peso);
            ruas[b].emplace_back(a, peso);
        }

        double ans = dijkstra(n, ruas);
        cout << fixed << setprecision(6) << ans << " percent"<< endl;
    }
}
