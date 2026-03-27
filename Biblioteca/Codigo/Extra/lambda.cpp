long long ans = 0;

auto lambda_padrao = [&](int x, int y) -> int {
    return x + y;
};

auto lambda_generica = [&](const auto &v) {
    return (int)v.size();
};

auto lambda_recursiva = [&](auto &&self, int x) -> int {
    if (x <= 1) return 1;
    return x * self(self, x - 1);
};

function<void(int, int)> dfs = [&](int v, int dir) {
    if (color[v] == -1) color[v] = dir;
    if (dir) cur1++;
    else cur2++;

    visited[v] = 1;
    for (auto u :graph[v]){
        if (color[u] == color[v]) bi = false;
        if (visited[u])  continue;

        dfs(u,!dir);
    }
};

auto reduce = [&](const multiset<string> &ms) -> multiset<int> {
    multiset<int> mi;
    for (const auto &s : ms) {
        if (s.size() > 1) {
            mi.insert((int)s.size());
            ans++;
        } else {
            mi.insert(s[0] - '0');
        }
    }
    return mi;
};

