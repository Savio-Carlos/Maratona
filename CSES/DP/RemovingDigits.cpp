#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9+7;
const int MAXS = 1e6+7;

vector<int> dp(MAXS, 0);

int largestDigit(int num) {
    int maxDigit = 0;
    string numStr = to_string(num);
    for (char c : numStr) {
        maxDigit = max(maxDigit, c - '0');
    }
    return maxDigit;
}

signed main() {
    int n;
    cin >> n;
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        int m = largestDigit(i);
        if (i-m >= 0) dp[i] += dp[i - m] + 1;
    }

    /*for (int i = 1; i <= n; i++) {
        cout << dp[i] << " ";    
    }
    cout << endl;
*/
    cout << dp[n] << endl;
    return 0;
}
