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

    template<typename... T>
    ostream& operator<<(ostream& os, const tuple<T...>& t);

    template<typename T_container, typename T = typename enable_if<!is_same_v<T_container, string> && !is_same_v<T_container, string_view>, typename T_container::value_type>::type>
    ostream& operator<<(ostream& os, const T_container& v) {
        os << '{';
        bool first = true;
        for (const T& x : v) { os << (first ? "" : ", ") << x, first = false; }
        return os << '}';
    }

    template<typename T1, typename T2>
    ostream& operator<<(ostream& os, const pair<T1, T2>& p) { return os << '{' << p.first << ", " << p.second << '}'; }

    template<typename... T>
    ostream& operator<<(ostream& os, const tuple<T...>& t) {
        os << '{';
        apply([&os](auto const&... args) {
            size_t n = 0;
            ((os << args << (++n != sizeof...(T) ? ", " : "")), ...);
        }, t);
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &u : a) cin >> u;

    set<pair<int,int>> in, out;
    for (int i = 0; i < n; i++) out.insert({a[i], i});
    int ans = 0;

    for (int i = 0; i < n; i++){
        in.insert({a[i] + i, i});
        out.erase({a[i], i});

        if (i >= k){
            out.insert({a[i-k], i-k});
            in.erase({a[i-k] + i-k , i-k});
        } 
        
        int mn_out = (out.empty() ? 1e18 : out.begin()->first);
        auto [mn_in, j] = *in.begin();
        mn_in += k-i;

        debug(mn_out, mn_in);
        debug(in);
        ans = max(ans, min(mn_out, mn_in));
    }
    cout << ans << endl;
    
}

/*
because for my current interval, the value of element at idx j will be a[j] + k - (i-j)
which is a[j] + j + k - i
because k and i are constants (for the interval that ends at i)
the the equation is just a[j] + j, because i will remove k - i from all elements,
so to discover the minimum in current interval i cand just sort them by (a[j] + j)
*/