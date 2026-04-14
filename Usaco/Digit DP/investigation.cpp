#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define ll long long
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

int dp[10][100][100][2]; // [index][sum][mod][tight]
int n;
string s;
int D;

int pd(int index, int sum, int m, int tight){
    if(index == n) {
        return (sum == 0 && m == 0);
    }
    if (dp[index][sum][m][tight] != -1) return dp[index][sum][m][tight];
 
    int ub = tight ? s[index] - '0' : 9;
    int ans = 0;

    for (int digit = 0; digit <= ub; digit++){
        int new_tight = tight && (digit == ub);

        int new_sum = (sum + digit) % D;
        int new_mod = (m * 10 + digit) % D;  

        ans += pd(index + 1, new_sum, new_mod, new_tight);
    }
    return dp[index][sum][m][tight] = ans; 
}

int count(int x){
    memset(dp, -1, sizeof(dp));
    s = to_string(x);
    n = s.size();
    return pd(0,0,0,1);
}

int solve(){
    int l, r;
    cin >> l >> r >> D;
    if (D > 90) return 0;
    else return (count(r) - count(l-1));
}

signed main(){
    winton;
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++){
        cout << "Case " << i << ": " << solve() << endl; 
    } 
}