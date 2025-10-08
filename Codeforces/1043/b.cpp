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

int fastExpo(int base, int exp) {
    int res = 1;
    while(exp) {
        if (exp & 1) res = res * base;
        base = base * base;
        exp >>= 1;
    }
    return res;
}

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    set<string, greater<string>> ans;
    for (int i = 1; i < n; i++){
        string t = "";
        string nxt = s.substr(0, i);
        int cur = stoll(nxt);
        t += nxt;
        for (int j = 0; j < n; j++){
            if (stoll(s) - stoll(t)*(fastExpo(10,j)) == stoll(t)) ans.insert(t);
        }
        debug(nxt, cur);
        for (int j = i; j + i < n; j += i){
            nxt = s.substr(j, i);
            int ad = max(0LL, stoll(nxt) - cur); 
            nxt = to_string(ad);
            cur = ad;
            if (ad) t += nxt;
            while (t.size() < j+i) {t += "0";}
            debug(nxt, ad, cur, t);
        }
        //debug(stoll(s), stoll(t), stoll(t)*(fastExpo(10,i)));
        for (int j = 0; j < n; j++){
            if (stoll(s) - stoll(t)*(fastExpo(10,j)) == stoll(t)) ans.insert(t);
        }
    }
    // bool unique = true;
    // for (int i = 1; i < n; i++){
    //     if (s[i] != s[i-1]) unique = false;
    // }
    // if (unique && !(n&1)) ans.insert(s.substr(0,n/2));

    cout << ans.size() << endl;
    if (ans.size()) {for (auto u : ans) cout << u << " "; cout << endl;}
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--) solve();
    
}