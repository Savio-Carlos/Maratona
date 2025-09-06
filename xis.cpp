#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int long long

#define endl "\n"
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
    #define minecraft (void)0
    #define debug(...) cerr << BOLD_BLUE << "[" << __func__ << ":" << __LINE__ << "]" << RESET << " "; debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
    #define minecraft ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
    #define debug(...) (void)0
#endif

int nxt(){
    int x;
    cin>>x;
    return x;
}

ld fastExpo(ld base, int exp) {
    ld res = 1;
    while(exp) {
        if (exp & 1) res = res * base;
        base = base * base;
        exp >>= 1;
    }
    return res;
}

bool valid(ld h, ld hn, ld b, ld n){
    ld bb = ((b-1)/b);
    ld calc = h * fastExpo(bb,n);
    debug(calc, bb, n);
    return hn < calc;
}

signed main (){
    minecraft;
    int t = 1;
    cin>>t;
    while(t--){
        int h,hn,b;
        cin>>h>>hn>>b;
        int l = 0, r = 1e18;
        while (l < r){
            int mid = l + ((r-l)/2);
            debug(mid);
            if (!valid(h,hn,b,mid)){
                r = mid;
            }
            else {
                l = mid+1;
            }
        }

        cout<<l<<endl;
    }
}