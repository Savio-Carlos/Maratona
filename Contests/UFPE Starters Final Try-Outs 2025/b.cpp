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

//#define DEBUG

#if defined(DEBUG)
    #define winton (void)0
    #define debug(...) cerr << BOLD_BLUE << "[" << __func__ << ":" << __LINE__ << "]" << RESET << " "; debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
    #define winton ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
    #define debug(...) (void)0
#endif


ld dist(ld x1, ld y1, ld x2, ld y2){
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

signed main(){
    winton;
    cout << fixed << setprecision(12);
    int n;
    ld tot; 
    cin >> n >> tot;
    vector<pair<ld, ld>> v;
    for(int i = 0; i < n; i++){
        ld a, b; cin >> a >> b;
        v.push_back({a, b});
    }
    if(tot == 0.0){
        cout << v[0].second << endl;
        return 0;
    }

    vector<ld> pfx;
    vector<ld> pfxmx;
    pfx.push_back(0.0);
    pfxmx.push_back(0.0);

    for(int i = 0; i < n-1; i++){
        auto [a, b] = v[i];
        auto [c, d] = v[i+1];
        // cout << sqrt(dist(a, b, c, d)) << "+ ";
        pfx.push_back(pfx.back() + dist(a, b, c, d));
        pfxmx.push_back(max(pfxmx.back(), b));
    }
    pfxmx.push_back(max(pfxmx.back(), v[n-1].second));


    auto it = lower_bound(pfx.begin(), pfx.end(), tot);
    int st = it - pfx.begin();
    debug(v);
    debug(pfx);
    ld ans = pfxmx[st];

    if (it == pfx.end()){
        cout << ans << endl;
        return 0;
    }
    debug(pfxmx);
    debug(ans);

    ld rem = tot - pfx[st-1];
    debug(rem);

    auto [x1,y1] = v[st-1];
    auto [x2,y2] = v[st];

    debug(x1,x2,y1,y2);

    ld m = (y2 - y1) / (x2 - x1);
    ld c = y1 - m*x1;
    debug(m,c,x2-x1,y2-y1);

    ld l = x1,  r = x2;
    for (int i = 0; i < 60; i++){
        ld mid = (l + r) / 2.0;
        
        ld yf = m*mid + c;
        ld d = dist(x1,y1,mid,yf);
        debug(mid, yf,l,r, d);

        if (d < rem){
            l = mid;
            ans = max(ans,yf);
        } 
        else r = mid;

        debug(mid);
    }

    cout << ans << endl;
}