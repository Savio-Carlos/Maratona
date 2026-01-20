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

/// #define DEBUG

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
    vector<int> a(n), d(n);
    for (auto &u : a) cin >> u;
    for (auto &u : d) cin >> u;

    vector<int> l(n), r(n);
    for(int i = 0; i < n; i++) {
        l[i] = i - 1;
        r[i] = i + 1;
    }

    vector<int> check;
    vector<int> ans;
    for(int i = 0; i < n; i++) check.push_back(i);

    while(!check.empty()) {
        set<int> dead;

        for (auto u : check){
            int damage = 0;
            if (l[u] >= 0) damage += a[l[u]];
            if (r[u] < n) damage += a[r[u]];
            if (damage > d[u]) dead.insert(u);
        }

        ans.push_back(dead.size());
        if(dead.empty()) break;

        vector<int> next;

        for (auto u : dead){
            if (l[u] >= 0) r[l[u]] = r[u];
            if (r[u] < n) l[r[u]] = l[u];
            if (l[u] >= 0 && !dead.count(l[u])) next.push_back(l[u]);
            if (r[u] < n && !dead.count(r[u])) next.push_back(r[u]);
        }
        sort(all(next));
        next.erase(unique(next.begin(), next.end()), next.end());
        check = next; 
    }
    for (auto u : ans) cout << u << " ";
    for (int i = 0; i < n-ans.size(); i++) cout << "0 ";
    cout << endl;
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--) solve();
}