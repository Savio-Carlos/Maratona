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
    int n, p, k;
    cin >> n >> p >> k;
    vector<int> a(n);
    for (auto &u : a) cin >> u;
    vector<vector<int>> s(n, vector<int>(p));
    for (int i = 0; i < n; i++){
        for (auto &u : s[i]) cin >> u;
    }

    vector<int> ord(n);
    iota(all(ord), 0);

    // sort indices by a descending values ina 
    sort(all(ord), [&](int i, int j) {
        return a[i] > a[j];
    });

    vector<int> a2(n);
    vector<vector<int>> s2(n, vector<int>(p));

    for (int i = 0; i < n; i++) {
        a2[i] = a[ord[i]];
        s2[i] = s[ord[i]];
    }

    a.swap(a2);
    s.swap(s2);

    int tot = (1 << p);
    debug(tot);

    vector<vector<int>> dp(n+1, vector<int>(tot));

    for (int i = 1; i <= n; i++){
        
        for (int mask = 0; mask < tot; mask++){//check all masks
            if (__popcount(mask) > i) continue;//if mask has more occupied positions than could have been filled, not valid

            for (int pos = 0; pos < p; pos++){ // where person i will be placed
                if (!((1 << pos) & mask)) continue; //cant place person i here, already occupied
                
                int pmask = mask ^ (1 << pos);
                //i can replace the max strength found for dp[i][mask]
                // for the new strength found for dp[i-1][pmask] + s[i][pos]

                dp[i][mask] = max(dp[i][mask], s[i-1][pos] + dp[i-1][pmask]);
                debug(i,mask,pos,pmask,s[i-1][pos]);
            }
                
            //actually i can place person i in the andience, if there is room
            //number of people in the andience is i - popcount(mask), beaceuse i ordered by biggest strength in the audience
            //if i have available seats in the audience, i must add a[i]

            int not_chosen = i - __popcount(mask);
            debug(a[i-1], mask, not_chosen, k); 
            if (not_chosen <= k && not_chosen) dp[i][mask] = max(dp[i][mask], dp[i-1][mask] + a[i-1]);
            else dp[i][mask] = max(dp[i][mask], dp[i-1][mask]);
            
        }
        debug(dp);
    }
    debug(dp);
    cout << dp[n][tot-1] << endl;
}

signed main(){
    winton;
    int t = 1;
    // cin >> t;
    while(t--) solve();
}