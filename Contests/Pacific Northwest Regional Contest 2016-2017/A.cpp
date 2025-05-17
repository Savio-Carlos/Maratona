#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAXN = 1e3+7;
const int MOD = 1e9+7;

int dp[MAXN][MAXN];

signed main(){
    winton;
    string alpha = "abcdefghijklmnopqrstuvwxyz";
    string s;
    cin >> s;
    int n = s.length();
    int m = alpha.length();
    int ans = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if(s[i-1] == alpha[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
            ans = max(ans,dp[i][j]);
        }
    }
    cout << 26 - ans << endl;

}