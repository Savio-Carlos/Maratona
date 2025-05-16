#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAXN = 1e6+7;
const int MOD = 1e9+7;
const int INF = INT_MAX;

int dp[MAXN]; 

signed main(){
    winton;
    int n, k;
    cin >> k >> n;
    vector<int> coins(k);
    for (int &i : coins) cin >> i;
    dp[0] = 1;
    for (int i = 1; i <= k; i++){
        for (int j = 1; j <= n; j++){
            int u = coins[i-1];
            if (j - u >= 0){
                dp[j] = (dp[j]+dp[j-u]) % MOD;
            }
        }   
    }
    cout << dp[n] % MOD << endl;
}