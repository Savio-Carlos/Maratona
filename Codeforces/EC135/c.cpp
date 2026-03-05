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

// #define DEBUG

#if defined(DEBUG)
    #define winton (void)0
    #define debug(...) cerr << BOLD_BLUE << "[" << __func__ << ":" << __LINE__ << "]" << RESET << " "; debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
    #define winton ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
    #define debug(...) (void)0
#endif


void solve(){
    int n;
    cin >> n;
    vector<string> sa(n), sb(n);
    for (auto &u : sa) cin >> u;
    for (auto &u : sb) cin >> u;

    int ans = 0;
    multiset<string> a(all(sa)), b(all(sb));

    // tirar numeros iguais
    for (auto it = a.begin(); it != a.end();) {
        auto it2 = b.find(*it);
        if (it2 != b.end()) {
            b.erase(it2);
            it = a.erase(it);
        } 
        else it++;
    }

    // reduzir todos a < 10

    auto reduce = [&](multiset<string> ms){
        multiset<int> mi;
        for (auto &s : ms) {
            if (s.size() > 1) {
                mi.insert(s.size());
                ans++;
            } 
            else mi.insert(s[0] - '0');
        }
        return mi;
    };
    
    multiset<int> va = reduce(a);
    multiset<int> vb = reduce(b);

    // tirar iguais de novo
    for (auto it = va.begin(); it != va.end();) {
        auto it2 = vb.find(*it);
        if (it2 != vb.end()) {
            vb.erase(it2);
            it = va.erase(it);
        } 
        else it++;
    }

    // reduzir restantes pra 1
    for (auto &u : va) if (u != 1) ans++;
    for (auto &u : vb) if (u != 1) ans++;
    cout << ans << endl;
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--) solve();
}