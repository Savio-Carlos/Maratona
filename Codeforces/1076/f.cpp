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

const int INF = 1e18;

void solve(){
    int n, x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    vector<int> x(n), y(n);
    for (auto &u : x) cin >> u;
    for (auto &u : y) cin >> u;
    map<int, pair<int,int>> mp;
    mp[x1] = {y1,y1};
    mp[x2] = {y2,y2};
    for (int i = 0; i < n; i++){
        auto xx = x[i];
        auto yy = y[i];
        if (mp.count(xx)){
            mp[xx].first = min(yy, mp[xx].first);
            mp[xx].second = max(yy, mp[xx].second);
        }
        else mp[xx] = {yy, yy};
    }
    debug(mp);

    int m = mp.size();
    vector<vector<int>> dp(2, vector<int>(m));
    dp[0][0] = 0;
    dp[1][0] = 0;
    int prevx = x1;
    int yprevmax = y1; 
    int yprevmin = y1;

    int i = 0;
    for (auto [x, ys] : mp){
        if (i == 0){
            i++;
            continue;
        } 
        auto [ymin, ymax] = ys;
        debug(x, ymin, ymax);
        int xcost = x - prevx;
        int ycost = ymax - ymin;
        debug(xcost, ycost);
        dp[0][i] = xcost + ycost + min(dp[0][i-1] + abs(yprevmin - ymax), dp[1][i-1] + abs(yprevmax - ymax));
        dp[1][i] = xcost + ycost + min(dp[0][i-1] + abs(yprevmin - ymin), dp[1][i-1] + abs(yprevmax - ymin));
        debug(i, dp[0][i], dp[1][i]);
        i++;
        yprevmax = ymax;
        yprevmin = ymin;
        prevx = x;
    }
    debug(dp);
    cout << dp[0][m-1] << endl;
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--) solve();
}