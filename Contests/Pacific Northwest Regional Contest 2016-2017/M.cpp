#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAXN = 55;
const int MOD = 1e9+7;

// dp[i][0] = length of longest zigzag ending at index i with a decreasing element
// dp[i][1] = length of longest zigzag ending at index i with an increasing element
int dp[MAXN][2];

signed main() {
    winton;
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &u : a) cin >> u;
    
    // Initialize dp with base value 1 (each element is a zigzag of length 1)
    for (int i = 0; i < n; i++) {
        dp[i][0] = dp[i][1] = 1;
    }
    
    int ans = 1; // At minimum, we have a subsequence of length 1
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            // If a[i] > a[j], we can extend a decreasing sequence with an increasing element
            if (a[i] > a[j]) {
                dp[i][1] = max(dp[i][1], dp[j][0] + 1);
            }
            // If a[i] < a[j], we can extend an increasing sequence with a decreasing element
            else if (a[i] < a[j]) {
                dp[i][0] = max(dp[i][0], dp[j][1] + 1);
            }
        }
        // Update the maximum length found so far
        ans = max(ans, max(dp[i][0], dp[i][1]));
    }
    
    cout << ans << endl;
    return 0;
}