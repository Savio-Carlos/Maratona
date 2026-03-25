#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define endl '\n'
#define ll long long

typedef double ld;
const ld eps = 1e-9;

bool eq(ld a, ld b) {
    return abs(a - b) <= eps;
}

struct pt { // ponto
    ld x, y;
    pt(ld x_ = 0, ld y_ = 0) : x(x_), y(y_) {}
    bool operator < (const pt p) const {
        if (!eq(x, p.x)) return x < p.x;
        if (!eq(y, p.y)) return y < p.y;
        return 0;
    }
    bool operator == (const pt p) const {
        return eq(x, p.x) and eq(y, p.y);
    }
    pt operator + (const pt p) const { return pt(x + p.x, y + p.y); }
    pt operator - (const pt p) const { return pt(x - p.x, y - p.y); }
    pt operator * (const ld c) const { return pt(x * c, y * c); }
    pt operator / (const ld c) const { return pt(x / c, y / c); }
    ld operator * (const pt p) const { return x * p.x + y * p.y; }
    ld operator ^ (const pt p) const { return x * p.y - y * p.x; }
};

ld sarea(pt p, pt q, pt r) { // area com sinal (cross product / 2)
    return ((q - p) ^ (r - q)) / 2;
}

bool col(pt p, pt q, pt r) { // se p, q e r sao colineares
    return eq(sarea(p, q, r), 0);
}

bool ccw(pt p, pt q, pt r) { // se p, q, r sao counter-clockwise
    return sarea(p, q, r) > eps;
}

// Retorna 0 se ta fora, 1 se ta no interior e 2 se ta na borda
int inpol(vector<pt>& v, pt p) { 
    int qt = 0;
    for (int i = 0; i < (int)v.size(); i++) {
        if (p == v[i]) return 2;
        int j = (i + 1) % v.size();
        if (eq(p.y, v[i].y) and eq(p.y, v[j].y)) {
            if ((v[i] - p) * (v[j] - p) < eps) return 2;
            continue;
        }
        bool baixo = v[i].y + eps < p.y;
        if (baixo == (v[j].y + eps < p.y)) continue;
        auto t = (p - v[i]) ^ (v[j] - v[i]);
        if (eq(t, 0)) return 2;
        if (baixo == (t > eps)) qt += baixo ? 1 : -1;
    }
    return qt != 0;
}

vector<pt> convex_hull(vector<pt> v) { 
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    if (v.size() <= 1) return v;
    vector<pt> l, u;
    for (int i = 0; i < (int)v.size(); i++) {
        while (l.size() > 1 and !ccw(l.end()[-2], l.end()[-1], v[i]))
            l.pop_back();
        l.push_back(v[i]);
    }
    for (int i = (int)v.size() - 1; i >= 0; i--) {
        while (u.size() > 1 and !ccw(u.end()[-2], u.end()[-1], v[i]))
            u.pop_back();
        u.push_back(v[i]);
    }
    l.pop_back(); u.pop_back();
    for (pt i : u) l.push_back(i);
    return l;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(10);

    int n;
    long double h_in;
    cin >> n >> h_in;

    map<pair<ll, ll>, ll> best;
    for (int i = 0; i < n; i++) {
        long double x, y, z;
        cin >> x >> y >> z;
        ll X = llround(x * 100.0L);
        ll Y = llround(y * 100.0L);
        ll Z = llround(z * 100.0L);
        
        if (best.count({X, Y})) best[{X, Y}] = max(best[{X, Y}], Z);
        else best[{X, Y}] = Z;
    }

    long double cx, cy;
    cin >> cx >> cy;
    pt cookie(cx, cy);
    ll CX = llround(cx * 100.0L);
    ll CY = llround(cy * 100.0L);

    vector<pair<pt, ll>> islands;
    vector<ll> zes;

    for (auto [coords, Z] : best) {
        if (coords.first == CX && coords.second == CY) continue; 
        
        pt p((ld)coords.first / 100.0, (ld)coords.second / 100.0);
        islands.push_back({p, Z});
        zes.push_back(Z);
    }

    sort(all(zes));
    zes.erase(unique(all(zes)), zes.end());

    auto check = [&](ll mid) -> bool {
        vector<pt> ativos;
        for (const auto& [p, z] : islands) {
            if (z >= mid) ativos.push_back(p);
        }

        if (ativos.size() < 3) return false;

        vector<pt> hull = convex_hull(ativos);
        bool pode = (inpol(hull, cookie) == 1);

        if (hull.size() == 4 && pode) {
            pode = false;
            if (!col(cookie, hull[0], hull[2]) || !col(cookie, hull[1], hull[3])) {
                pode = true;
            } else {
                for (auto x : ativos) {
                    if (!col(x, hull[0], hull[2]) && !col(x, hull[1], hull[3])) {
                        pode = true;
                        break;
                    }
                }
            }
        }

        return pode;
    };

    if (zes.empty()) {
        cout << -1 << endl;
        return 0;
    }

    int l = 0, r = (int)zes.size() - 1;
    int best_idx = -1;

    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check(zes[mid])) {
            best_idx = mid;
            l = mid + 1;
        } else {
            r = mid - 1; 
        }
    }

    if (best_idx == -1) {
        cout << -1 << endl;
    } else {
        long double best_mid = (long double)zes[best_idx] / 100.0L;
        cout << max<long double>(0.0L, h_in - best_mid) << endl;
    }

    return 0;
}