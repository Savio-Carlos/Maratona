#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define int long long
#define ld long double

namespace dbg {
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
        cerr << s.substr(0, cpos) << " = " << h;
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
    #define debug(...) cerr << "[" << __func__ << ":" << __LINE__ << "]" << " "; debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
    #define winton ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
    #define debug(...) (void)0
#endif

int dp[20][11][2][20]; // [index][last][tight][ldz]
int n;
string s;

int pd(int index, int last, int tight, int ldz){
    if(index == n) return 1;
 
    if (dp[index][last][tight][ldz] != -1) return dp[index][last][tight][ldz];
 
    int ub = tight ? s[index] - '0' : 9;
    int ans = 0;

    for (int digit = 0; digit <= ub; digit++){
        if (!ldz && last == digit) continue;
        
        int new_tight = tight && (digit == ub);
        int new_ldz = (digit == 0) && ldz;
        
        int next = new_ldz ? 10 : digit;

        ans += pd(index + 1, next, new_tight, new_ldz);
    }
    return dp[index][last][tight][ldz] = ans; 
}

int count(int x){
    memset(dp, -1, sizeof(dp));
    s = to_string(x);
    n = s.size();
    return pd(0,10,1,1);
}

signed main(){
    winton;
    int l, r;
    cin >> l >> r;
    cout << count(r) - count(l-1) << endl;
}