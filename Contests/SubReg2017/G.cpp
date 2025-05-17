#include <bits/stdc++.h>
using namespace std;
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long
#define ld long double
const int MOD = 1e9+7;

signed main() {
    winton;
    int t, m, n;
    cin >> t >> m >> n;
    int col = n-m+1;
    vector<vector<int>> dp (t, vector<int> (col+2));

    for (int i = 1; i <= col; i++){
        dp[0][i] = 1;
    }
    for (int i = 1; i < t; i++){
        for (int j = 1; j <= col; j++){
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];
        }
    }
    int ans = 0;
    for (int j = 1; j <= col; j++){
        ans += dp[t-1][j] % MOD;
    }
    cout << ans % MOD << endl;
}