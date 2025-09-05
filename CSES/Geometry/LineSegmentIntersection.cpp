#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define int long long
#define ld long double

namespace dbg {
    const char* const RESET     = "\033[0m";
    const char* const BOLD_BLUE = "\033[1;34m";
    const char* const YELLOW    = "\033[33m";
    const char* const BOLD_WHITE= "\033[1;37m";

    template<typename T1, typename T2>
    ostream& operator<<(ostream& os, const pair<T1, T2>& p) { return os << '{' << p.first << ", " << p.second << '}'; }

    template<typename T_container, typename T = typename enable_if<!is_same_v<T_container, string> && !is_same_v<T_container, string_view>, typename T_container::value_type>::type>
    ostream& operator<<(ostream& os, const T_container& v) {
        os << '{';
        bool first = true;
        for (const T& x : v) { os << (first ? "" : ", ") << x, first = false; }
        return os << '}';
    }

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

#define DEBUG

#if defined(DEBUG)
    #define winton (void)0
    #define debug(...) cerr << BOLD_BLUE << "[" << __func__ << ":" << __LINE__ << "]" << RESET << " "; debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
    #define winton ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
    #define debug(...) (void)0
#endif

const int MAX = 1e5+7;


struct point {
    int x, y;
    point(int x_ = 0, int y_ = 0) : x(x_), y(y_) {}
    bool operator == (const point p) const {
		return x == p.x and y == p.y;
	}
	point operator + (const point p) const { return point(x+p.x, y+p.y); }
	point operator - (const point p) const { return point(x-p.x, y-p.y); }
	point operator * (const int c) const { return point(x*c, y*c); }
	int operator * (const point p) const { return x*(int)p.x + y*(int)p.y; }
	int operator ^ (const point p) const { return x*(int)p.y - y*(int)p.x; }
    
    friend istream& operator >> (istream& in, point& p) {
		return in >> p.x >> p.y;
	}

    friend ostream& operator << (ostream& os, point& p) {
		return os << "(" << p.x << ", " << p.y << ")"; 
	}
};

struct line {
	point p, q;
	line() {}
	line(point p_, point q_) : p(p_), q(q_) {}
    
    friend istream& operator >> (istream& in, line& r) {
		return in >> r.p >> r.q;
	}

    friend ostream& operator << (ostream& os, line& r) {
		return os << "[" << r.p << " -> " << r.q << "]";
	}
};

int sq(point p){
    return p.x*p.x + p.y*p.y;
}

double abs(point p){
    return sqrt(sq(p));
}

//ccw, 0 colineares, -1 r a direita, 1 r a esquerda
int orientation(point p, point q, point r){
    int val = ((q-p) ^ (r-p));
    if (!val) return 0;
    return (val > 0) ? 1 : -1;
}

bool isinseg(point p, line r) { // se p pertence ao seg de r
	point a = r.p - p, b = r.q - p;
	return (a ^ b) == 0 and (a * b) <= 0;
}

bool intersect(line r, line s){
    int o1 = orientation(r.p, r.q, s.p);
    int o2 = orientation(r.p, r.q, s.q);
    int o3 = orientation(s.p, s.q, r.p);
    int o4 = orientation(s.p, s.q, r.q);

    if (o1 != o2 && o3 != o4) return true;

    if (o1 == 0 && isinseg(s.p, r)) return true;
    if (o2 == 0 && isinseg(s.q, r)) return true;
    if (o3 == 0 && isinseg(r.p, s)) return true;
    if (o4 == 0 && isinseg(r.q, s)) return true;

    return false;
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--){
        line r, s;
        cin >> r >> s;
        debug(r, s);
        debug(orientation(r.p, s.p, r.q));
        if (intersect(r,s)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}