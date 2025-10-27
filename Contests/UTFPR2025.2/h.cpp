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
 
// #define DEBUG
 
#if defined(DEBUG)
    #define winton (void)0
    #define debug(...) cerr << BOLD_BLUE << "[" << __func__ << ":" << __LINE__ << "]" << RESET << " "; debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
    #define winton ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
    #define debug(...) (void)0
#endif

struct point {
    ld x, y;
    point(ld x_ = 0, ld y_ = 0) : x(x_), y(y_) {}
    ld operator * (const point p) const { return x*p.x + y*p.y; }
    ld operator ^ (const point p) const { return x*p.y - y*p.x; }
    friend ostream& operator << (ostream& os, const point& p) { return os << "(" << p.x << ", " << p.y << ")"; }
};

signed main(){
    ld r, x, y;
    cin >> r >> x >> y;
    x = fabs(x);
    y = fabs(y);
    point p(x,y);
    point a = {sqrt((r*r) - (y*y)), y};
    point b = {x, sqrt((r*r) - (x*x))};
    point c = {-sqrt((r*r) - (y*y)), y};
    point d = {x, -sqrt((r*r) - (x*x))};
    debug(a, b, c, d);

    vector<ld> ans;

    ld areaOAP = fabs((p^a) / 2.0);  
    ld areaOBP = fabs((p^b) / 2.0);  
    ld areaOCP = fabs((p^c) / 2.0);  
    ld areaODP = fabs((p^d) / 2.0);  
    
    ld areaAB = (r*r) * acos((a*b)/(ld)(r*r)) / 2.0;
    ld areaCA = (r*r) * acos((a*c)/(ld)(r*r)) / 2.0;
    ld areaCD = (r*r) * acos((c*d)/(ld)(r*r)) / 2.0;
    ld areaDB = (r*r) * acos((d*b)/(ld)(r*r)) / 2.0;
    
    debug(areaAB, areaCA, areaCD, areaDB);
    debug(areaOAP, areaOBP, areaOCP, areaODP);
    
    ld quadAB = areaAB - (areaOAP + areaOBP);
    ld quadCD = areaCD + (areaOCP + areaODP);
    ld quadCB = areaCA - (areaOAP + areaOCP) - quadAB;
    ld quadDA = areaDB - (areaODP + areaOBP) - quadAB;

    ans.push_back(quadAB); // qyadrante AB
    ans.push_back(quadCD);
    ans.push_back(quadCB); // 
    ans.push_back(quadDA); // quadrante AD

    sort(all(ans));
    cout << fixed << setprecision(3);
    for (auto u : ans) cout << u << " "; 
    
}