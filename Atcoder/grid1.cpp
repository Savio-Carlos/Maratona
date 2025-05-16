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

int h, w, dp[MAXN][MAXN];

signed main(){
    winton;
    cin >> h >> w;

    for (int i = 1; i <= h; i++){
        for (int j = 1; j <= w; j++){
            char a;
            cin >> a;
            if (a == '#') dp[i][j] = -1;
        }
    }
    dp[1][1] = 1;
    for (int i = 1; i <= h; i++){
        for (int j = 1; j <= w; j++){
            if (dp[i][j] == -1) continue;
            if (dp[i-1][j] != -1) dp[i][j] = (dp[i][j] + dp[i-1][j])%MOD;
            if (dp[i][j-1] != -1) dp[i][j] = (dp[i][j] + dp[i][j-1])%MOD;
        }
    }
    cout << dp[h][w]%MOD << endl;
}