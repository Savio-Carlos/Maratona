#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAXN = 1e5+7;

struct DSU {
    vector<int> comp, rank;
    DSU(int n): comp(n), rank(n, 0) {
        iota(comp.begin(), comp.end(), 0);
    }
    int find(int x) {
        return comp[x] == x ? x : comp[x] = find(comp[x]);
    }
    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (rank[a] < rank[b]) swap(a, b);
        comp[b] = a;
        if (rank[a] == rank[b]) ++rank[a];
    }
};

signed main(){  
    winton;
    int n, q, d;
    cin >> n >> q >> d;
    vector<pair<int,int>> points(n);
    map<pair<int,int>, int> mp;

    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
        mp[points[i]] = i;
    }

    DSU dsu(n);
    for (int i = 0; i < n; ++i) {
        int x = points[i].first;
        int y = points[i].second;
        for (int dx = -d; dx <= d; ++dx) {
            for (int dy = -d; dy <= d; ++dy) {
                if (dx == 0 && dy == 0) continue;
                if (dx*dx + dy*dy > d*d) continue;
                auto pp = mp.find({x + dx, y + dy});
                if (pp != mp.end()) {
                    dsu.unite(i,pp->second);
                }
            }
        }
    }
    while (q--) {
        int s, t;
        cin >> s >> t;
        if (dsu.find(s-1) == dsu.find(t-1)) cout << "S" << endl;
        else cout << "N" << endl;
    }
}
