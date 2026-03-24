#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

void dbg_out() { cerr << endl; }
template<typename H, typename... T> 
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }

// #define DEBUG

#if defined(DEBUG)
    #define fastio (void)0
    #define debug(...) cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__);
#else
    #define fastio ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(...) (void)0
#endif

const int MOD = 998244353;

signed main(){
    fastio;
    int n; 
    cin >> n;
    // map<int,int> sum;
    vector<int> a(n);
    for (auto &u : a) cin >> u;
    vector<int> sum(1e5+2);
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        auto &s = sum[a[i-1]];
        dp[i] = dp[i-1];
        dp[i] = (dp[i] + s) % MOD;
        s = (s + dp[i-1]) % MOD;
    }
    cout << dp[n] << endl;
}