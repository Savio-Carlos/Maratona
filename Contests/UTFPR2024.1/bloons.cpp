#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    vector<int> bloons(N);
    vector<int> monkey(K);
    for (int i = 0; i < N; i++) {
        cin >> bloons[i];
    }
    for (int i = 0; i < K; i++) {
        cin >> monkey[i];
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        int res = bloons[i]; 
        vector<int> dp(res + 1, LLONG_MAX);
        dp[0] = 0;
        for (int j = 0; j < K; j++) {
            for (int x = monkey[j]; x <= res; x++) {
                if (dp[x - monkey[j]] != LLONG_MAX) {
                    dp[x] = min(dp[x], dp[x - monkey[j]] + 1);
                }
            }
        }
        if (dp[res] == LLONG_MAX) {
            cout << -1 << endl;
            return 0;
        }
        ans += dp[res];
    }
    
    cout << ans << endl;

    return 0;
}
