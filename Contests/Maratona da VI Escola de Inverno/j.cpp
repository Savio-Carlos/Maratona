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

#define DEBUG

#if defined(DEBUG)
    #define winton (void)0
    #define debug(...) cerr << BOLD_BLUE << "[" << __func__ << ":" << __LINE__ << "]" << RESET << " "; debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
    #define winton ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
    #define debug(...) (void)0
#endif

struct pt {
    int x, y;
    pt(int x_ = 0, int y_ = 0) : x(x_), y(y_) {}

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
    auto operator * (const pt& p) const { return (int)x * p.x + (int)y * p.y; }
    auto operator ^ (const pt& p) const { return (int)x * p.y - (int)y * p.x; }

    friend istream& operator >> (istream& in, pt& p) { return in >> p.x >> p.y; }
    friend ostream& operator << (ostream& os, const pt& p) { return os << "(" << p.x << ", " << p.y << ")"; }
};

signed main(){
    winton;
    int n, m;
    cin >> n >> m;
    vector<tuple<int,int,int>> jangadas(n);
    vector<pt> peixes(m);
    for (auto &[x,r,y] : jangadas) cin >> x >> r >> y;
    for (auto &p : peixes) cin >> p;

    map<int,int> ymx;
    for (auto [x,r,y] : jangadas){
        for (int i = x-r; i <= x+r; i++){
            int d = abs(x-i); 
            int h = y + sqrt(r*r - d*d);
            if (ymx.count(i)) ymx[i] = max(ymx[i], h);
            else ymx[i] = h;
        }
    }
    debug(peixes);
    debug(ymx);
    
    int ans = 0;
    for (auto [x,y] : peixes){
        if (ymx.count(x)){
            if(ymx[x] >= y) ans++;
        }   
    }
    cout << ans << endl;
}
/*
o raio de cada jangada e <= 10
entao cada jangada cobre no maximo 20 pontos
todas as coordendas sao inteiras
N*20 = 2e6
da para passar por todos os pontos X das jangadas e ver qual jangada tem o melhor y para aquele x
depois passo pelos peixes e vejo quantos naquele X sao pegos
*/