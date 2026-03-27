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

function<void(int, int)> dfs = [&](int v, int p) {
    for (auto u :graph[v]){
        if (u == v) continue;
        dfs(u,v);
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

