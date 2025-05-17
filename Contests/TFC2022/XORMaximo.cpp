#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAXS = 1e5+7;

int dp[3010][(1<<15)];
int a[3010];
int n;
signed main () {
    winton;
    cin >> n;
    for (int i = 1; i <= n ;i++){
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    int ini = 0;
    while(a[n] >= (1<<15) && n!=0){
        ini^=a[n];
        n--;
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < (1<<15); j++){
            dp[i][j] = dp[i-1][j] | dp[i-1][j^a[i]];
        }
    }
    int ans = 0;
    for (int i = 0; i < (1<<15); i++){
        if (dp[n][i] == 1)ans = max(ans, (ini^i));
    }
    cout << ans << endl;
} 