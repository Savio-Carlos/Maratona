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

const int INF = LLONG_MAX;

void solve(){
    int n, kmax;
    cin >> n >> kmax;
    string s, t;
    cin >> s >> t;
    if (s == t){
        cout << 0 << endl;
        return;
    }
    int k = kmax;

    map<char, int> lastt;
    map<char, int> lasts;
    for (int i = 0; i < n; i++) lastt[t[i]] = i;
    for (int i = 0; i < n; i++) lasts[s[i]] = i;
    
    debug(lasts);
    debug(lastt);
    vector<string> ans;

    while (k--){
        if (s == t) break;
        for (int i = n-1; i > 0; i--){
            if (s[i] != t[i] && (s[i-1]) == t[i]) s[i] = s[i-1];
            else if (lastt[s[i-1]] >= i && lasts[s[i-1]] == i-1){//tenho um cara la pra frente entao preciso propagar
                s[i] = s[i-1];
            }
            //falta uns if aqui
        }

        debug(s);
        ans.push_back(s);
        for (int i = 0; i < n; i++) lastt[t[i]] = i;
        for (int i = 0; i < n; i++) lasts[s[i]] = i;

        if (s == t) break;
    }
    if (s != t){
        cout << "-1\n";
        return;
    }
    cout << kmax - k << endl;
    for (auto r : ans) cout << r << endl;
}

signed main () {
    winton;
    int t;
    cin >> t;
    while(t--) solve();
}