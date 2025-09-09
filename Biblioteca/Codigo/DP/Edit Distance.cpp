//Edit Distance
int dp[MAX][MAX];

string s, t;
cin >> s >> t;
int n = s.length();
int m = t.length();
for (int i = 1; i <= n; i++){
    for (int j = 1; j <= m; j++){
        if(s[i-1] == t[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
        else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }
}