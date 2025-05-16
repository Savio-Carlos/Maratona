#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
using namespace std;
#define endl '\n'
#define int long long

signed main() {_
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        int sum = 0;
        for (char c : s) {
            sum += c - '0';
        }
        vector<bool> dp(9, false);
        dp[sum % 9] = true;

        for (char c : s) {
            int numer = c - '0';
            vector<bool> new_dp(dp);
            if (numer == 2 || numer == 3) {
                int quadrado = numer * numer;
                for (int r = 0; r < 9; ++r) {
                    if (dp[r]) {
                        int new_r = (r - numer + quadrado + 9) % 9;
                        new_dp[new_r] = true;
                    }
                }
            }

            dp = new_dp;
        }
        if (dp[0]) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
