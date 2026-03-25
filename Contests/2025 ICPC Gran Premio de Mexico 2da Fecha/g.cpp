#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define ll long long
#define ld long double

namespace dbg {
    const char* const RESET     = "\033[0m";
    const char* const BOLD_BLUE = "\033[1;34m";
    const char* const YELLOW    = "\033[33m";
    const char* const BOLD_WHITE= "\033[1;37m";

    template<typename T1, typename T2>
    ostream& operator<<(ostream& os, const pair<T1, T2>& p);

    template<typename T_container, typename T = typename enable_if<!is_same_v<T_container, string> && !is_same_v<T_container, string_view>, typename T_container::value_type>::type>
    ostream& operator<<(ostream& os, const T_container& v) {
        os << '{';
        bool first = true;
        for (const T& x : v) { os << (first ? "" : ", ") << x, first = false; }
        return os << '}';
    }

    template<typename T1, typename T2>
    ostream& operator<<(ostream& os, const pair<T1, T2>& p) { return os << '{' << p.first << ", " << p.second << '}'; }

    void debug_out(string_view) { cerr << endl; }
    template<typename H, typename... T>
    void debug_out(string_view s, H h, T... t) {
        auto cpos = s.find(',');
        cerr << YELLOW << s.substr(0, cpos) << RESET << " = ";
        cerr << BOLD_WHITE << h << RESET;
        if constexpr (sizeof...(t) > 0) {
            cerr << ", ";
            auto nx = s.find_first_not_of(" \t\n\r", cpos + 1);
            debug_out(s.substr(nx), t...);
        } else {
            cerr << endl;
        }
    }
} 
using namespace dbg;

// #define DEBUG

#if defined(DEBUG)
    #define winton (void)0
    #define debug(...) cerr << BOLD_BLUE << "[" << __func__ << ":" << __LINE__ << "]" << RESET << " "; debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
    #define winton ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
    #define debug(...) (void)0
#endif

//Geometria Double
const ld DINF = 1e18;
const ld pi = acos(-1.0);
const ld eps = 1e-12;

#define sq(x) ((x)*(x))

bool eq(ld a, ld b) {
	return fabs(a - b) <= eps;
}

ll to_cents(ld v) {
    return llround(v * 100.0L);
}

struct point { // ponto
	ld x, y, h;
	point(ld x_ = 0, ld y_ = 0, ld h_ = 0) : x(x_), y(y_), h(h_) {}
	bool operator < (const point p) const {
		if (!eq(x, p.x)) return x < p.x;
		if (!eq(y, p.y)) return y < p.y;
		return 0;
	}
	bool operator == (const point p) const {
		return eq(x, p.x) and eq(y, p.y);
	}
	point operator + (const point p) const { return point(x+p.x, y+p.y); }
	point operator - (const point p) const { return point(x-p.x, y-p.y); }
	point operator * (const ld c) const { return point(x*c  , y*c  ); }
	point operator / (const ld c) const { return point(x/c  , y/c  ); }
	ld operator * (const point p) const { return x*p.x + y*p.y; }
	ld operator ^ (const point p) const { return x*p.y - y*p.x; }
	friend istream& operator >> (istream& in, point& p) {
		return in >> p.x >> p.y >> p.h;
	}
    friend ostream& operator << (ostream& os, const point& p) { return os << "(" << p.x << ", " << p.y << ", h: " << p.h << ")"; }
};

ld angle(const point &p, const point &ref) { // angulo do ponto p em relacao ao ponto ref
    point v = p - ref;
    ld ang = atan2(v.y, v.x);
    if (ang < 0) ang += 2*pi;
    return ang;
}

//ordena os pontos de acordo com o angulo
void polarSort(vector<point> &v, point &ref) {
    sort(v.begin(), v.end(), [&ref](point a, point b) { 
        ld aa = angle(a, ref);
        ld ab = angle(b, ref);
        if (!eq(aa, ab)) return aa < ab;
        point da = a - ref;
        point db = b - ref;
        return (da * da) < (db * db);
    });
}

signed main(){
    winton;
    cout << fixed << setprecision(10);

    int n; 
    ld hh;
    cin >> n >> hh;  
    map<pair<ll,ll>, ld> best;
    for (int i = 0; i < n; i++){
        ld x, y, h;
        cin >> x >> y >> h;
        pair<ll, ll> key = {to_cents(x), to_cents(y)};
        if (best.count(key)) best[key] = max(best[key], h);
        else best[key] = h;
    }
    
    point cookie;
    cin >> cookie.x >> cookie.y;
    pair<ll, ll> cookie_key = {to_cents(cookie.x), to_cents(cookie.y)};
    debug(cookie);

    vector<point> points;
    for (auto [pt,h] : best){
        auto [x, y] = pt;
        if (pt == cookie_key) continue;
        point p(x,y,h);
        p.x = (ld)x / 100.0L;
        p.y = (ld)y / 100.0L;
        points.push_back(p);
    }
    debug(points);

    auto polar = points;
    polarSort(polar, cookie);
    debug(polar);

    vector<pair<ld, ld>> islands;

    for (auto u : polar){
        debug(u, angle(u,cookie));
        islands.emplace_back(angle(u,cookie), u.h);
    }

    vector<ld> zes;
    for (const auto &p : points) zes.push_back(p.h);
    sort(all(zes));
    zes.erase(unique(all(zes)), zes.end());

    auto check = [&](ld mid) -> bool {
        vector<ld> angles;
        for (auto [ang, hh] : islands) {
            if (hh + eps >= mid) angles.push_back(ang);
        }
        int m = angles.size();

        if (m < 3) return false;

        ld max_gap = 0.0L;
        for (int j = 1; j < m; j++) {
            ld ang1 = angles[j];
            ld ang2 = angles[j-1];

            ld diff = fabs(ang1-ang2);
            max_gap = max(diff, max_gap);
        }
        max_gap = max(max_gap, angles[0] + 2.0L * pi - angles.back());
        return max_gap + eps < pi - eps;
    };

    if (zes.empty()) {
        cout << -1 << endl;
        return 0;
    }

    int l = 0, r = zes.size() - 1;
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
        return 0;
    }

    ld best_mid = zes[best_idx];
    cout << max<ld>(0.0L, hh - best_mid) << endl;
}