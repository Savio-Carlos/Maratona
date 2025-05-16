#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;
const int MAXS = 1e6+7;
 
vector<int> dp(MAXS, 0);
 
signed main(){
    int n, ans;
    cin >> n >> ans;
    vector<int> coins(n);
    for(int i = 0; i < n; i++){
        cin >> coins[i];
        dp[coins[i]]++;
    }
    dp[0] = 0;
 
    for(int i = 0; i <= ans; i++){
            for (auto u : coins){
                if (i - u > 0) dp[i] += dp[i-u]%MOD;
            }
    }
    cout << dp[ans]%MOD << endl;
}