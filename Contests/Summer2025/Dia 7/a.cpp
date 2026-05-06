
#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define int long long
#define ld long double

namespace dbg {
    constexpr const char* RESET      = "\033[0m";
    constexpr const char* BOLD_BLUE  = "\033[1;34m";
    constexpr const char* YELLOW     = "\033[33m";
    constexpr const char* BOLD_WHITE = "\033[1;37m";

    template<typename T, typename = void> struct is_container : false_type {};
    template<typename T> struct is_container<T, void_t<typename T::value_type>> : bool_constant<!is_same_v<T, string> && !is_same_v<T, string_view>> {};

    inline ostream& print_atom(ostream& os, bool b)         { return os << (b ? "true" : "false"); }
    inline ostream& print_atom(ostream& os, char c)         { return os << '\'' << c << '\''; }
    inline ostream& print_atom(ostream& os, const string& s){ return os << '"' << s << '"'; }
    inline ostream& print_atom(ostream& os, string_view s)  { return os << '"' << s << '"'; }
    inline ostream& print_atom(ostream& os, const char* s)  { return os << '"' << s << '"'; }

    template<typename T, enable_if_t<!is_container<T>::value, int> = 0>
    ostream& print_atom(ostream& os, const T& x) { return os << x; }

    template<typename T1, typename T2>
    ostream& print_atom(ostream& os, const pair<T1, T2>& p) {
        os << '{'; print_atom(os, p.first); os << ", "; print_atom(os, p.second); return os << '}';
    }
    template<typename... T>
    ostream& print_atom(ostream& os, const tuple<T...>& t) {
        os << '{';
        apply([&os](auto const&... args) {
            size_t n = 0;
            ((print_atom(os, args), os << (++n != sizeof...(T) ? ", " : "")), ...);
        }, t);
        return os << '}';
    }

    template<typename T, typename C>
    ostream& print_atom(ostream& os, stack<T, C> s) {
        os << '{'; bool f = true; while (!s.empty()) { if (!f) os << ", "; print_atom(os, s.top()); s.pop(); f = false; } return os << '}';
    }
    template<typename T, typename C>
    ostream& print_atom(ostream& os, queue<T, C> q) {
        os << '{'; bool f = true; while (!q.empty()) { if (!f) os << ", "; print_atom(os, q.front()); q.pop(); f = false; } return os << '}';
    }
    template<typename T, typename C, typename Cmp>
    ostream& print_atom(ostream& os, priority_queue<T, C, Cmp> q) {
        os << '{'; bool f = true; while (!q.empty()) { if (!f) os << ", "; print_atom(os, q.top()); q.pop(); f = false; } return os << '}';
    }

    template<typename C, enable_if_t<is_container<C>::value, int> = 0>
    ostream& print_atom(ostream& os, const C& v) {
        os << '{'; bool f = true;
        for (const auto& x : v) { if (!f) os << ", "; print_atom(os, x); f = false; }
        return os << '}';
    }

    template<typename C, enable_if_t<is_container<C>::value, int> = 0>
    ostream& operator<<(ostream& os, const C& v)            { return print_atom(os, v); }
    template<typename T1, typename T2>
    ostream& operator<<(ostream& os, const pair<T1, T2>& p) { return print_atom(os, p); }
    template<typename... T>
    ostream& operator<<(ostream& os, const tuple<T...>& t)  { return print_atom(os, t); }

    inline size_t split_arg(string_view s) {
        int depth = 0;
        for (size_t i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (c == '"' || c == '\'') {
                char q = c; ++i;
                while (i < s.size() && s[i] != q) { if (s[i] == '\\' && i + 1 < s.size()) ++i; ++i; }
            } else if (c == '(' || c == '[' || c == '{' || c == '<') ++depth;
            else if (c == ')' || c == ']' || c == '}' || c == '>') --depth;
            else if (c == ',' && depth == 0) return i;
        }
        return string_view::npos;
    }

    inline void debug_out(string_view) { cerr << '\n' << flush; }
    template<typename H, typename... T>
    void debug_out(string_view s, const H& h, const T&... t) {
        size_t cpos = split_arg(s);
        auto name = s.substr(0, cpos);
        while (!name.empty() && (name.front() == ' ' || name.front() == '\t')) name.remove_prefix(1);
        while (!name.empty() && (name.back()  == ' ' || name.back()  == '\t')) name.remove_suffix(1);
        cerr << YELLOW << name << RESET << " = " << BOLD_WHITE;
        print_atom(cerr, h) << RESET;
        if constexpr (sizeof...(t) > 0) {
            cerr << ", ";
            debug_out(cpos == string_view::npos ? string_view{} : s.substr(cpos + 1), t...);
        } 
        else cerr << '\n' << flush;
    }
}
using namespace dbg;

// #define DEBUG

#if defined(DEBUG)
    #define winton (void)0
    #define debug(...) do { cerr << BOLD_BLUE << "[" << __func__ << ":" << __LINE__ << "] " << RESET; dbg::debug_out(#__VA_ARGS__, __VA_ARGS__); } while (0)
#else
    #define winton ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
    #define debug(...) ((void)0)
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

ld angle(point v) { // angulo do vetor com o eixo x
	ld ang = atan2(v.y, v.x);
	if (ang < 0) ang += 2*pi;
	return ang;
}

ld sarea(point p, point q, point r) { // area com sinal
	return ((q-p)^(r-q))/2;
}

bool col(point p, point q, point r) { // se p, q e r sao colin.
	return eq(sarea(p, q, r), 0);
}

bool ccw(point p, point q, point r) { // se p, q, r sao ccw
	return sarea(p, q, r) > eps;
}

ld dist(point p, point q) { // distancia
	return hypot(p.y - q.y, p.x - q.x);
}

ld norm(point v) { // norma do vetor
	return dist(point(0, 0), v);
}

ld inner_angle(point p, point q, point mid){ //angulo interno entre duas linhas, mid e o ponto de intersecao entre elas
    point p1 = (p-mid);
    point p2 = (q-mid);
    ld rad = atan2(abs(p1 ^ p2), p1 * p2);//angulo em rad
    ld deg = rad* 180.0 / pi;
    return rad;
}

vector<point> convex_hull(vector<point> v) { // convex hull - O(n log(n))
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	if (v.size() <= 1) return v;
	vector<point> l, u;
	for (int i = 0; i < v.size(); i++) {
		while (l.size() > 1 and !ccw(l.end()[-2], l.end()[-1], v[i]))
			l.pop_back();
		l.push_back(v[i]);
	}
	for (int i = v.size() - 1; i >= 0; i--) {
		while (u.size() > 1 and !ccw(u.end()[-2], u.end()[-1], v[i]))
			u.pop_back();
		u.push_back(v[i]);
	}
	l.pop_back(); u.pop_back();
	for (point i : u) l.push_back(i);
	return l;
}

signed main(){
    winton;
    int n;
    ld raio;
    cin >> n >> raio;
    vector<point> points;
    for (int i = 0;  i < n; i++){
        int k;
        cin >> k;
        while(k--){
            point p;
            cin >> p;
            points.push_back(p);
        }
    }
    ld ans = 0;

    auto cvx = convex_hull(points);
    // vector<line> lines;
    for (int i = 0; i < cvx.size(); i++){
        // lines.push_back(line(cvx[i], cvx[(i+1)%cvx.size()]));
        ans += dist(cvx[i], cvx[(i+1)%cvx.size()]);
    }
    // debug(cvx);
    // int m = lines.size();
    // for (int i = 0; i < m; i++){
    //     auto r = lines[i];
    //     auto s = lines[(i+1)%m];
    //     //transformar de interno para externo
    //     ld graus = pi - inner_angle(r.p, s.q, r.q);
    //     debug(graus);
    //     ans += graus * raio;
    // }
    //bobao

    cout << fixed << setprecision(10) << ans + pi*raio*2 << endl;
}