#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXS = 1e5+7;
const int MOD = 1e9 + 7;

int main() {
    ll n;
    cin >> n;
    vector<ll> dp(n+7);
    dp[0] = 1; 
    dp[1] = 1; 
    dp[2] = 2; 
    dp[3] = 4; 
    dp[4] = 8; 
    dp[5] = 16; 
    dp[6] = 32;

    for (int i = 7; i <= n; i++){
        dp[i] = dp[i-6] + dp[i-5] + dp[i-4] + dp[i-3] + dp[i-2] + dp[i-1];
        dp[i] = dp[i] % MOD;
    }
    
    cout << dp[n] << endl;
}