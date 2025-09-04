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
};

struct line {
	point p, q;
	line() {}
	line(point p_, point q_) : p(p_), q(q_) {}
    
    friend istream& operator >> (istream& in, line& r) {
		return in >> r.p >> r.q;
	}
};

int dot(point p, point q) {
    return p.x * q.x + p.y * q.y;
}

int cross (point p, point q){
    return p.x * q.y - p.y * q.x;
}

bool perpendicular(point v, point w){
    return (dot(v,w) == 0);
}

//ccw
int orientation(point p, point q, point r){
    int val = cross(q-p, r-p);
    if (!val) return 0;
    return (val > 0) ? 1 : -1;
}

//checa se um ponto esta contido no angulo do segmento pq e pr
bool onAngle (point p, point q, point r, point g){
    if (!orientation(p,q,r)) return false;
    if (orientation(p,q,r) > 0) swap(q,r);
    return orientation(p,q,g) >= 0 && orientation(p,r,g) <= 0; 
}

int sq(point p){
    return p.x*p.x + p.y*p.y;
}

double abs(point p){
    return sqrt(sq(p));
}

double pointdist(point p, point q){
    return sqrt(sq(p.x - q.x) + sq(p.y - q.y));
}

double linepointdist(line s, point r){
    point p = s.p;
    point q = s.q;
    return cross((p-r), (q-r))/pointdist(p,q);
}

signed main(){
    winton;
    // p = 1,1
    // q = 4,2
    // r = 2,3
    point p, q, r;
    cin >> p >> q >> r;
    line s(p,q);
    cout << pointdist(p,q) << endl;
    cout << linepointdist(s,r) << endl;
    debug(abs(q));
    debug(sq(q));
    debug(orientation(p,q,r));
    debug(orientation(p,r,q));
}