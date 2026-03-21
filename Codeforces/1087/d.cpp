#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
// #define endl '\n'
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
    int r, g, b;
    cin >> r >> g >> b;
    vector<pair<int, char>> a = {{r, 'R'}, {g, 'G'}, {b, 'B'}};
    sort(all(a));
    
    auto& [cnt0, ch0] = a[0];
    auto& [cnt1, ch1] = a[1];
    auto& [cnt2, ch2] = a[2];
    debug(cnt0,cnt1,cnt2);
    
    if (cnt2 > cnt0 + cnt1 + 1) cnt2 = cnt0 + cnt1 + 1;
    
    int n = cnt0 + cnt1 + cnt2;
    int odd = (n+1)/2;
    int even = n/2;
    
    string ans(n, ' ');
    
    int idxo = 0;
    int idxe = (even - 1) * 2 + 1;

    for (int i = 0; i < odd - cnt2; i++) {
        debug(odd-cnt2);
        ans[idxo] = ch0;
        idxo += 2;
    }
    debug(idxo);
    debug(ans);
    for (int i = 0; i < cnt2; i++) {
        ans[idxo] = ch2;
        idxo += 2;
    }
    debug(ans);
    
    for (int i = 0; i < even - cnt1; i++) {
        ans[idxe] = ch0;
        idxe -= 2;
    }
    debug(ans);
    for (int i = 0; i < cnt1; i++) {
        ans[idxe] = ch1;
        idxe -= 2;
    }
    cout << ans << endl;
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--) solve();
}