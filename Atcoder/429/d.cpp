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

const int MAX = 2e5+7;

int cnt[MAX];

signed main(){
    winton;
    int n, m, c;
    cin >> n >> m >> c;
    map<int,int> mp;
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        mp[a]++;
    }
    vector<pair<int,int>> a;
    for (auto [w, q] : mp){
        a.push_back({q,w});
    }
    debug(mp);
    debug(a);
    int nn = a.size();
    vector<pair<int,int>> pfx(2*nn);
    for (int i = 0; i < 2*nn; i++){
        if (i < nn){
            pfx[i] = a[i];
            debug(i);
        } 
        else {
            pfx[i].second = a[i%nn].second + m; 
            pfx[i].first = a[i%nn].first;
        }
        if (i) pfx[i].first += pfx[i-1].first;
    }
    debug(pfx);
    int ans = 0;
    for (int i = 0; i < nn; i++){
        int goal = pfx[i].first + c;
        auto it = lower_bound(pfx.begin(), pfx.end(), make_pair(goal,0LL));
        debug(*it);
        int met = (*it).first - pfx[i].first;
        if (pfx[i].second + 1 == m) ans += met;
        else ans += (pfx[i+1].second - pfx[i].second) * met;
        debug(ans);
        //(pfx[i+1].second - pfx[i].second) saber quantos caras tem essa pfx
    }
    cout << ans << endl;
}


