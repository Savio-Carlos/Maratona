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
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> particles(n), shop(m);
    map<int,vector<int>> mp;

    vector<int> mn(n+1,0);
    for (auto &[x,y] : particles){
        cin >> x >> y;
        mp[y].push_back(x); 
    } 
    for (auto &[x,y] : shop) cin >> x >> y;

    debug(mp);
    vector<int> best(n+1);
    multiset<int> mt;
    int sum = 0;
    for (auto u : mp[n]){
        mt.insert(u);
        sum += u;
        if (mt.size() > n) {
            auto it = mt.begin();
            sum -= *it;
            mt.erase(it);
        }
    }

    for (int i = n; i ; i--){
        for (auto u :mp[i-1]){
            mt.insert(u);
            sum += u;
            if (mt.size() > i) {
                auto it = mt.begin();
                sum -= *it;
                mt.erase(it);
            }
        } 
        if (mt.size() > i) {
            auto it = mt.begin();
            sum -= *it;
            mt.erase(it);
        }
        mn[i] = mt.size() == i ? *mt.begin() : 0LL;
        best[i] = sum;
        debug(mt);
    }
    int melhor = *max_element(all(best));

    debug(best);
    debug(mn);
    debug(melhor);
    
    for (auto [x,y] : shop){
        cout << max({melhor, best[y+1] - mn[y+1] + x, x}) << " ";
    }
   
    cout << endl;
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--) solve();
}