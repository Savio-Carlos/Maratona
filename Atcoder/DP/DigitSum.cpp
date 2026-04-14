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

const int MOD = 1e9+7;

int dp[10007][107][2][2]; // [index][mod][tight][ldz]
int n;
string s;
int D;

int pd(int index, int m, int tight, int ldz){
    if(index == n) return (m == 0);
 
    if (dp[index][m][tight][ldz] != -1) return dp[index][m][tight][ldz];
 
    int ub = tight ? s[index] - '0' : 9;
    int ans = 0;

    for (int digit = 0; digit <= ub; digit++){
        int new_mod = (m + digit) % D;
        
        int new_tight = tight && (digit == ub);
        int new_ldz = (digit == 0) && ldz;

        ans = (ans + pd(index + 1, new_mod, new_tight, new_ldz) % MOD) % MOD;
    }
    return dp[index][m][tight][ldz] = ans % MOD; 
}

signed main(){
    winton;
    memset(dp, -1, sizeof(dp));
    cin >> s >> D; 
    n = s.size();
    cout <<  (pd(0,0,1,1) - 1 + MOD) % MOD << endl;
}