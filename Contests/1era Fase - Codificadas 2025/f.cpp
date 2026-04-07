#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int long long
#define ld long double
#define endl '\n'

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


const ld DINF = 1e18;
const ld pi = acos(-1.0);
const ld eps = 1e-9;
#define sq(x) ((x)*(x))

bool eq(ld a, ld b) {
	return fabs(a - b) <= eps;
}

struct point { // ponto
	ld x, y;
	point(ld x_ = 0, ld y_ = 0) : x(x_), y(y_) {}
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
		return in >> p.x >> p.y;
	}
    friend ostream& operator << (ostream& os, const point& p) { 
        return os << "(" << p.x << ", " << p.y << ")"; 
    }
};

struct line { // reta
	point p, q;
	line() {}
	line(point p_, point q_) : p(p_), q(q_) {}
	friend istream& operator >> (istream& in, line& r) {
		return in >> r.p >> r.q;
	}
};

signed main(){
    winton;
    int n;
    cin >> n;
    vector<point> segmentos(n);
    for (auto &p : segmentos) cin >> p;
    map<point,int> mp;
    debug(segmentos);
    string ans = "NO";
    for (int i = 0; i < n; i++){
        auto [x1,y1] = segmentos[i];
        for (int j = i+1; j < n; j++){
            auto [x2,y2] = segmentos[j];
            point m = {(x1+x2)/2.0, (y1+y2)/2.0};
            debug(m);
            if (mp.count(m)) ans = "YES";
            mp[m] = 1;
        }
    }
    cout << ans << endl;
}
