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

signed main(){
    winton;
    int n, m;   
    cin >> n >> m;
    vector<int> a(n);
    for (auto &u : a) cin >> u;
    sort(all(a));
    auto b = a;
    for (auto u : a) b.push_back(u+m);

    int nn = 2*n;
    vector<int> pfx(nn+1), sfx(nn+1);
    
    int cur = 0;
    for (int i = 0; i < nn; i++){
        cur += b[i];
        pfx[i+1] = cur;
    }

    cur = 0;
    for (int i = nn-1; i >= 0; i--){
        cur += b[i];
        sfx[i] = cur;
    }

    debug(b);
    debug(pfx);
    debug(sfx);

    int ans = 1e18;

    for (int l = 0, r = n-1; l < n; l++, r++){
        int mid = l + n/2;
        int med = b[mid];
        
        debug(med);
        
        int l_sum = pfx[mid] - pfx[l];
        int r_sum = sfx[mid] - sfx[r+1];

        int cost = (med * (mid - l) - l_sum) + (r_sum - med * (r - mid + 1));
        ans = min(ans, cost);
    }
    cout << ans << endl;
}
