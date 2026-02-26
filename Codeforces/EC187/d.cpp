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

void solve(){
    int n, m;
    cin >> n >> m;
    
    vector<int> a(n), b(m);
    for (auto &u : a) cin >> u; 
    for (auto &u : b) cin >> u;
    
    sort(all(a));
    a.erase(unique(all(a)), a.end());
    debug(a);
    
    int MAX = n+m+1;
    vector<bool> tem(MAX, false);
    ll l = 1;
    for (auto u : a){
        if (l <= MAX) l = lcm(l, u);
        if (tem[u]) continue;
        for (int i = u; i < MAX; i += u) tem[i] = 1;
    }
    debug(l);
    int ali = 0, bob = 0, c = 0;
    for (auto y : b){
        if (!tem[y]) bob++;
        else if (l <= MAX && (y % l == 0)) ali++;
        else c++;
    }

    debug(ali,bob,c);
    string ans;
    if (c&1){
        //coringas impar, alice pega o ultimo
        if (bob > ali) ans = "Bob";//bob tem que ter mais que alice para ganhar
        else ans = "Alice";
    }
    else {
        if (bob >= ali) ans = "Bob";//bob tem que ter mais ou igual que alice para ganhar
        else ans = "Alice";
    }
    cout << ans << endl;
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--) solve();
}