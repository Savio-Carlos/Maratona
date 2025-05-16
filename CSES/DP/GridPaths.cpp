#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9+7;
const int MAXS = 1e6+7;

int n;

bool check (int i, int j, vector<vector<int>>& dp){
    return (i >= 0 && i < n && j >= 0 && j < n && dp[i][j] != -1);
}

signed main() {
    cin >> n;
    vector<vector<int>> dp(n, vector<int> (n,0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            if (c == '*') dp[i][j] = -1;
        }
    }

    if (dp[0][0] != -1) dp[0][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dp[i][j] == -1) continue;

            if (check(i - 1, j, dp)) dp[i][j] += dp[i - 1][j];
            if (check(i, j - 1, dp)) dp[i][j] += dp[i][j - 1];
        }
    }


    /*for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }*/
  
    cout << (dp[n - 1][n - 1] == -1 ? 0 : dp[n - 1][n - 1]) << endl;

}