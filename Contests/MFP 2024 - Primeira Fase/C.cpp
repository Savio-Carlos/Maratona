#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MOD = 1e8;
const int MAXN = 3*(1e5)+7;
const int MAXM = 1e4+7;

int dp[MAXN];

signed main(){  
    winton;
    int n;
    cin >> n;
    vector<int> coins((1<<n), 0);

    for (int i = 0; i < (1<<n)-1; i++) cin >> coins[i];
    dp[0] = coins[0];
    for (int i = 0; i < (1<<n); i++){
        if (2*(i+1)-1 < (1<<n))   dp[2*(i+1)-1] = max(dp[2*(i+1)], dp[i] + coins[2*(i+1)-1]);
        if (2*(i+1) < (1<<n)) dp[2*(i+1)] = max(dp[2*(i+1)+1], dp[i] + coins[2*(i+1)]);
    }

    //for (int i = 0; i < (1<<n); i++) cout << dp[i] << " ";
    int ans = 0;
    for (int i = 0; i < (1<<(n)); i++) ans = max(ans, dp[i]);
    cout << ans << endl;
}