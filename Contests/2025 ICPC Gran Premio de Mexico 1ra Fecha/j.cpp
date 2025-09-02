#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int long long

#define endl "\n"

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
    #define bg3 (void)0
    #define debug(...) cerr << BOLD_BLUE << "[" << __func__ << ":" << __LINE__ << "]" << RESET << " "; debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
    #define bg3 ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
    #define debug(...) (void)0
#endif
//=============================================================================================================================================//

signed main() {
    bg3;
    int n;
    cin >> n;
    string s;
    cin >> s;
    int size = (1<<26);

    vector<int> first(size, -1);
    int mask = 0;
    first[0] = 0;
    int ans = 1;
    for (int i = 0; i < s.size(); i++) {
        int chab = s[i] - 'a';
        mask ^= (1 << chab);
        if (first[mask] != -1) ans = max(ans, (i - first[mask])+1);
        for (int k = 0; k < 26; ++k) {
            int targetmask = mask ^ (1 << k);
            if (first[targetmask] != -1) ans = max(ans, (i - first[targetmask])+1);
        }
        if (first[mask] == -1) first[mask] = i+1;
        // debug(ans);
        // debug(mask);
    }

    cout << ans << endl;
}