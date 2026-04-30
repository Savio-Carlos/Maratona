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
ans to total movement is difference between sum of final pos - sum of initial 
each row h with cnt[h] blocks will goto right n, n-1, ..., n-cnt[h]+1
remove is from top
removing top i cuts our initial pos sum by i
removing top block at i -> losing n-cnt[h]+1

*/
void solve(){
    int n;
    cin >> n;
    vector<int> a(n+1);
    int mx = 0;
    
    int sum = 0;
    map<int,int> freq;

    for (int i = 1; i <= n; i++){
        cin >> a[i];
        mx = max(mx, a[i]);
        freq[a[i]]++;
        sum += a[i] * i;
    }
    debug(sum);

    vector<int> cnt(mx+2, 0);
    for (int i = mx; i >= 1; i--){
        cnt[i] = cnt[i+1] + freq[i];
    }
    debug(cnt); 

    int tr = 0;
    for (int i = 1; i <= mx; i++){
        tr +=( cnt[i] * n) - (cnt[i] * (cnt[i] - 1)) / 2;
    }

    int ans = tr - sum;
    int best = 0;

    for (int i = 1; i <= n; i++){
        debug(i, a[i], cnt[a[i]]);
        int gain = i - n + cnt[a[i]] - 1;
        debug(i,best);
        best = max(best, gain);
    }

    cout << ans + best << endl;
}

signed main(){
    winton;
    int t = 1;
    cin >> t;
    while(t--) solve();
}