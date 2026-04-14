#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAXN = 1e4+7;
const int MAXM = 15;

int dp[MAXN][MAXN];

signed main(){
    winton;
    string s, t;
    cin >> s >> t;
    int n = s.length();
    int m = t.length();
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if(s[i-1] == t[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    string f = "";
    int i = n, j = m;
    while (i > 0 && j > 0){
        int mx = max(dp[i-1][j], dp[i][j-1]);
        if (dp[i][j] > dp[i-1][j] && dp[i][j] > dp[i][j-1]){
            f += s[i-1];
            i--;
            j--;
        }
        else if (dp[i-1][j] == mx) i--;
        else j--;
    }
    reverse(all(f));
    cout << f << endl;
}