#include <bits/stdc++.h>
using namespace std;

class DSU {
private:
    vector<int> comp;

public:
    DSU(int n) {
        comp.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            comp[i] = i;
        }
    }

    int find(int u) {
        if (comp[u] == u) return u;
        return comp[u] = find(comp[u]);
    }

    void unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u != v) {
            comp[v] = u;
        }
    }
};

int mst(int n, vector<pair<int, pair<int, int>>> &caminho) {
    DSU dsu(n);
    sort(caminho.begin(), caminho.end());
    int custo = 0;

    for (auto &edge : caminho) {
        int c = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;

        if (dsu.find(u) != dsu.find(v)) {
            dsu.unite(u, v);
            custo += c;
        }
    }

    return custo;
}

int main() {
    int n, f, r;
    cin >> n >> f >> r;

    vector<pair<int, pair<int, int>>> rodovias, ferrovias;

    while (f--) {
        int a, b, c;
        cin >> a >> b >> c;
        ferrovias.push_back({c, {b - 1, a - 1}});
    }
    while (r--) {
        int a, b, c;
        cin >> a >> b >> c;
        rodovias.push_back({c, {b - 1, a - 1}});
    }

    int fcost = mst(n, ferrovias);
    int rcost = mst(n, rodovias);

     cout << fcost << " " << rcost << endl;

    return 0;
}
