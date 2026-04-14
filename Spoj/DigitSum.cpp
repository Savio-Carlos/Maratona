#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define int long long
#define ld long double

void debug_out(string s, int line) {cerr << endl; }
template<typename H, typename... T>
void debug_out(string s, int line, H h, T... t){
    do{
        cerr << line << ": " << s[0]; s = s.substr(1);
    }
    while (s.size() and s[0] != ',');
    cerr << " = " << h;
    debug_out(s, line, t...);
}

// #define DEBUG

#if defined(DEBUG)
    #define winton (void)0
    #define debug(...) debug_out(#__VA_ARGS__, __LINE__, __VA_ARGS__)
#else
    #define winton ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(...) (void)0
#endif

int dp[16][200][2][2]; // [index][sum][tight][ldz]
int n;
string s;

int pd(int index, int sum, int tight, int ldz){
    if(index == n) return sum;
 
    if (dp[index][sum][tight][ldz] != -1) return dp[index][sum][tight][ldz];
 
    int ub = tight ? s[index] - '0' : 9;
    int ans = 0;

    for (int digit = 0; digit <= ub; digit++){
        int new_sum = (sum + digit);
        
        int new_tight = tight && (digit == ub);
        int new_ldz = (digit == 0) && ldz;

        ans += pd(index + 1, new_sum, new_tight, new_ldz);
    }
    return dp[index][sum][tight][ldz] = ans; 
}

int count(int x){
    memset(dp, -1, sizeof(dp));
    s = to_string(x);
    n = s.size();
    return pd(0,0,1,1);
}

void solve(){
    int l, r;
    cin >> l >> r;
    cout << count(r) - count(l-1) << endl;
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--) solve();
}