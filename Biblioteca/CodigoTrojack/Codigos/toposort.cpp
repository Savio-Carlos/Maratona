// Ordenação Topológica
// toposort: O(V + E logV)

vector<ll> graph[inf], indeg;

vector<ll> toposort(ll n) {
    vector<ll> ans;
    priority_queue<ll> topo;

    for (ll i = 1; i <= n; i++) {
        if (indeg[i] == 0) {
            topo.push(i);
        }
    }

    while (!topo.empty()) {
        auto v = topo.top();
        topo.pop();
        ans.push_back(v);
        for (auto u : graph[v]) {
            if (--indeg[u] == 0) {
                topo.push(u);
            }
        }
    }

    if ((ll)ans.size() != n) return {}; 
    return ans;
}