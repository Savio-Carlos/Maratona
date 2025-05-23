#include <bits/stdc++.h>
using namespace std;

static const int MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    // dp_prev[n] = number of partitions of n using parts in {1,2,...,p-1}
    // dp[n]      = number of partitions of n using parts in {1,2,...,p}
    vector<int> dp_prev(N+1, 0), dp(N+1, 0);
    dp_prev[0] = 1;  // There is exactly one way to partition 0: the empty partition.

    for (int p = 1; p <= N; ++p) {
        fill(dp.begin(), dp.end(), 0);

        if (p == K) {
            // We are forbidden to use any part of size K,
            // so DP[n][K] = DP[n][K-1] for all n.
            for (int n = 0; n <= N; ++n) {
                dp[n] = dp_prev[n];
            }
        } else {
            // Standard partition-DP recurrence:
            // DP[n][p] = DP[n][p-1] + (n >= p ? DP[n-p][p] : 0)
            for (int n = 0; n <= N; ++n) {
                // Count all partitions of n that do not use part p:
                long long val = dp_prev[n];
                if (n >= p) {
                    // Count those that do use part p at least once:
                    val += dp[n - p];
                    if (val >= MOD) val -= MOD;
                }
                dp[n] = int(val);
            }
        }

        // Move to the next p
        dp_prev.swap(dp);
    }

    // dp_prev[N] now holds DP[N][N] modulo 998244353
    cout << dp_prev[N] << "\n";
    return 0;
}
