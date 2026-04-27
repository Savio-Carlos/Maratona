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
/*
1 -1 3 -4 1 -3
_              = 1 -> (1,2)

1 -1 3 -4 1 -3
______         = 3 -> (1,4)

1 -1 3 -4 1 -3
___________    = 0 -> (1,6)

1 -1 3 -4 1 -3 
     _         = 3 -> (3,4)

1 -1 3 -4 1 -3
     ______    = 0 -> (3,6)

1 -1 3 -4 1 -3
          _    = 1 -> (5,6)

1 -1 3 -4 1 -3
   ___         = 2 -> (2,3)


1 2 3 4 5 6
4 1 5 2 6 3


   1 -1 3 -4 1 -3
0  1  0 3 -1 0   -> pfx sum

1  2  3 4  5 6
The value of inversion (i,j) = P[j-1] - P[i-1] 
We want this to be an inversion when P[j-1] > P[i-1]
NOT an inversion when P[j-1] < P[i-1]
if we sort
-1 0 0 0 1 3
 5 1 3 6 2 4

assign n-i to pos
6 5 4 3 2 1
5 1 3 6 2 4

p = 5 2 4 1 6 3
*/
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &u : a) cin >> u;

    vector<int> pfx(n);
    pfx[0] = 0;
    for (int i = 1; i < n; i++){
        pfx[i] = pfx[i-1] + a[i-1];
    }
    debug(pfx);
    vector<int> idx(n);
    iota(all(idx), 0);
    debug(idx);
    sort(all(idx), [&](int b, int c){ return pfx[b] < pfx[c]; });
    debug(idx);

    vector<int> p(n);
    for (int i = 0; i < n; i++){
        debug(idx[i], i, p[idx[i]]);
        p[idx[i]] = n - i;
    }
    debug(p);
    for (auto u : p) cout << u << " ";
    cout << endl;   
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--) solve();
}