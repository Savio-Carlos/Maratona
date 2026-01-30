#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define all(x) x.begin(), x.end()
#define endl '\n'

struct DSU {
    vector<int> id, sz;
    DSU(int n) : id(n), sz(n, 1){ 
        iota(id.begin(), id.end(), 0); 
    }

    int find(int a){
        return a == id[a] ? a : id[a] = find(id[a]); 
    }

    void unite(int a, int b){
        a = find(a), b = find(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a, b);
        sz[a] += sz[b], id[b] = a;
    }
};

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

signed main() {
    fastio;
    int n, r1, c1, r2, c2;
    cin >> n >> r1 >> c1 >> r2 >> c2;
    r1--, c1--, r2--, c2--;

    vector<string> g(n);
    for (int i = 0; i < n; i++) cin >> g[i];

    DSU dsu(n * n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (g[i][j] == '1') continue;
            for (int k = 0; k < 4; k++) {
                int ni = i + dx[k], nj = j + dy[k];
                if (ni >= 0 && ni < n && nj >= 0 && nj < n && g[ni][nj] == '0') {
                    dsu.unite(i * n + j, ni * n + nj);
                }
            }
        }
    }

    int s = dsu.find(r1 * n + c1), t = dsu.find(r2 * n + c2);
    if (s == t) {
        cout << 0 << endl;
        return 0;
    }

    vector<pair<int, int>> v1, v2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (g[i][j] == '1') continue;
            int cur = dsu.find(i * n + j);
            if (cur == s) v1.push_back({i, j});
            else if (cur == t) v2.push_back({i, j});
        }
    }

    int ans = 2e18;
    for (auto &p1 : v1) {
        for (auto &p2 : v2) {
            int dist = (p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second);
            ans = min(ans, dist);
        }
    }

    cout << ans << endl;
}