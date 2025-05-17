

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll NEG_INF = LLONG_MIN / 4;

int N, K;
vector<ll> x;                         
vector<vector<int>> children;         


vector<ll> dfs(int u) {
   
    vector<ll> dp(1, 0);

    
    for (int v : children[u]) {
        vector<ll> cd = dfs(v);
        
        if (dp.size() < cd.size()) dp.swap(cd);

        int su = dp.size() - 1;
        int sv = cd.size() - 1;
        int new_max = min(K, su + sv);
        vector<ll> nd(new_max + 1, NEG_INF);

        for (int i = 0; i <= su; i++) {
            if (dp[i] <= NEG_INF) continue;
            for (int j = 0; j <= sv && i + j <= K; j++) {
                if (cd[j] <= NEG_INF) continue;
                nd[i + j] = max(nd[i + j], dp[i] + cd[j]);
            }
        }
        dp.swap(nd);
    }

    if (u != 1) {
        if (dp.size() < 2) dp.resize(2, NEG_INF);
        dp[1] = max(dp[1], x[u]);
    }

    if ((int)dp.size() > K + 1) dp.resize(K + 1);
    return dp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    x.assign(N + 1, 0);
    for (int i = 2; i <= N; i++) {
        cin >> x[i];
    }
    children.assign(N + 1, {});
    for (int i = 2; i <= N; i++) {
        int p;
        cin >> p;
        children[p].push_back(i);
    }

    vector<ll> root_dp = dfs(1);
    ll ans = 0;
    if (K < (int)root_dp.size() && root_dp[K] > 0)
        ans = root_dp[K];
    cout << ans << "\n";
    return 0;
}
