#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

void solve(){
    string s;
    cin >> s;
    int n = s.size();

    vector<vector<int>> dp(n+1, vector<int>(n+1));

    
    for (int len = 2; len <= n; len++){
        for (int i = 0; i+len-1 < n; i++){
            int j = i+len-1;
            // cout << i << " i : j " << j << endl;
            if (s[i] == s[j]) dp[i][j] = (len == 2) ? 0 : dp[i+1][j-1];
            else dp[i][j] = min({dp[i+1][j], dp[i+1][j-1], dp[i][j-1]})+1;
        }
    }

    // for (int i = 0; i <= n; i++){
    //     for (int j = 0; j <= n; j++) cout << dp[i][j] << " "; 
    //     cout << endl;
    // }
    cout << dp[0][n-1] << endl;
}

int main (){
    fastio;
    int t;
    cin >> t;
    while (t--)solve();
}