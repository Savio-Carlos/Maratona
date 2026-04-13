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
always possible if p + q*2 == (n+1)*m + (m+1)*n
where n*m is size of grid

at most n*(m+1) or m*(n+1) q's

both sides times 2 and +1
(2n+1)*(2m+1) = 2p + 4q + 1

tot = 2p + 4q + 1;
2n + 1 = tot / (2m+1);

|_|_|_|_|_|_


*/

void solve(){
    int p, q;
    cin >> p >> q;
    int tot = p + 2*q;

    tot = tot*2 + 1;


    vector<int> divisors;
    for (int i = 1; i * i <= tot; ++i) {
        if (tot % i == 0) {
            divisors.push_back(i);
            if (i * i != tot) divisors.push_back(tot / i);
        }
    }
    debug(divisors);


    for (auto i : divisors){
        if (i&1 == 0) continue;
        
        int n2 = tot/i;
        int n = (n2 - 1) / 2;
        int m = (i - 1) / 2;

        if(!n || !m) continue;

        if (q <= n*(m+1) && q <= m*(n+1)){
            debug(n,m);
            cout << n << " " << m << endl;
            return;
        }
    }
    cout << -1 << endl;
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--) solve();
}