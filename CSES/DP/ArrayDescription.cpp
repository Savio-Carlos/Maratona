#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAXN = 1e5+1;
const int MAXM = 101;
const int MOD = 1e9+7;

int dp[MAXN][MAXM];

signed main(){
    winton;
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &u : a) cin >> u;

    if (a[0] == 0) {
		fill(dp[0], dp[0] + 101, 1);
	} else {
		dp[0][a[0]] = 1;
	}

    for (int i = 1; i < n; i++) {
		if (a[i] == 0) {
			for (int j = 1; j <= m; j++) {
            dp[i][j] += dp[i - 1][j];
            if (j-1 > 0) dp[i][j] += dp[i-1][j-1];
            if (j+1 <= m) dp[i][j] += dp[i-1][j+1];
            dp[i][j] %= MOD;
            }
        }
        else {
			dp[i][a[i]] += dp[i - 1][a[i]];
			if (a[i] - 1 > 0) dp[i][a[i]] += dp[i - 1][a[i] - 1];
			if (a[i] + 1 <= m) dp[i][a[i]] += dp[i - 1][a[i] + 1];
			dp[i][a[i]] %= MOD;
		}
    }
    int ans = 0;
    for (int i = 1; i <= m; i++) {
		ans += dp[n - 1][i];
		ans %= MOD;
	}
	cout << ans << endl;
}
