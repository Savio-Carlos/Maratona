#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAXN = 1e3+7;
const int MAXM = 15;

int dp[MAXN][MAXM];
int n, m, c0, d0, a[MAXN], b[MAXN], c[MAXN], d[MAXN];

signed main(){
    winton;
    cin >> n >> m >> c0 >> d0;
    for (int i = 1; i <= m; i++){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
 
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            for (int k = 0; k <= a[j]/b[j]; k++){
                if (i - c[j]*k >= 0){
                    dp[i][j] = max(dp[i][j], dp[i-c[j]*k][j-1] + d[j] * k);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= n; i++){
        ans = max(ans, dp[i][m] + ((n-i)/c0)*d0);
    }


    cout << ans << endl;
}