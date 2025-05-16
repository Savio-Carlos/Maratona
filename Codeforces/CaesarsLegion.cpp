#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAXN = 1e2+7;
const int MAXK = 12;
const int MOD = 1e8;

int n1, n2, k1, k2, dp[MAXN][MAXN][MAXK][MAXK];

int solve(int a, int b, int seg1, int seg2){
    if (a+b == n1+n2) return 1;
    if (dp[a][b][seg1][seg2] != -1) return dp[a][b][seg1][seg2];
    int ans = 0;

    if (a < n1 && seg1 < k1){
        ans += solve(a+1, b, seg1+1, 0) %MOD;
    }
    if ( b < n2 && seg2 < k2 ) {
        ans += solve(a, b+1, 0, seg2+1) %MOD;
    }
    return dp[a][b][seg1][seg2] = ans;
}

signed main(){  
    winton;
    cin >> n1 >> n2 >> k1 >> k2;
    memset(dp, -1, sizeof(dp));

    int p = solve(0,0,0,0);
    cout << p%MOD << endl;

}