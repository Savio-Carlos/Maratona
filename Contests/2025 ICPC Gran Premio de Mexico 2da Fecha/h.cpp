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

struct pt {
    ll x, y;
    pt(ll x_ = 0, ll y_ = 0) : x(x_), y(y_) {}

    bool operator < (const pt p) const {
		if (x != p.x) return x < p.x;
		return y < p.y;
	}

	bool operator == (const pt p) const {
		return x == p.x and y == p.y;
	}

    pt operator + (const pt& p) const { return pt(x + p.x, y + p.y); }
    pt operator - (const pt& p) const { return pt(x - p.x, y - p.y); }
    template<typename U>
    pt operator * (const U c) const { return pt(x * c, y * c); }
    auto operator * (const pt& p) const { return (ll)x * p.x + (ll)y * p.y; }
    auto operator ^ (const pt& p) const { return (ll)x * p.y - (ll)y * p.x; }

    friend istream& operator >> (istream& in, pt& p) { return in >> p.x >> p.y; }
    friend ostream& operator << (ostream& os, const pt& p) { return os << "(" << p.x << ", " << p.y << ")"; }
};

ll sq(pt p){
    return p.x*p.x + p.y*p.y;
}

ll dist2(pt p, pt q){
    return sq(p.x - q.x) + sq(p.y - q.y);
}

signed main(){
    winton;
    int n; 
    ll h, k;
    cin >> n >> h >> k;
    vector<pair<pt,bool>> points(n);
    for (auto &[p,z] : points) cin >> p >> z;
    
    pt start;
    cin >> start;
    if (!start.y){
        cout << 0 << endl;
        return 0;
    }

    int st;
    for (int i = 0; i < n; i++){
        auto [pi,zi] = points[i];
        if (pi == start) st = i;
    }
    
    vector<int> dist(n + 2, 1e9);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, st});
    dist[st] = 0;

    while (!pq.empty()) {
        auto [d, v] = pq.top();
        pq.pop();
        
        if (d > dist[v]) continue;
        
        auto [pi,zi] = points[v];
        
        pt e(pi.x, 0);
        if (zi && dist2(pi,e) <= h*h) {
            dist[n+1] = dist[v]+1;
            break;
        }
        for (int u = 0; u < n; u++) {
            if (u == v) continue;
            auto [pf,zf] = points[u];
            ll di = dist2(pi,pf);

            if ((zi && di <= h*h) || (zf && di <= k*k)){
                if (dist[v] + 1 < dist[u]) {
                    dist[u] = dist[v] + 1;
                    pq.push({dist[u], u});
                }
            }
        }
    }
    debug(dist);
    if (dist[n+1] == 1e9) cout << -1 << endl;
    else cout << dist[n+1] << endl;
}