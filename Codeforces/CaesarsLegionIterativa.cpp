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

int n1, n2, k1, k2, dp[MAXN][MAXN][MAXK];

signed main(){  
    winton;
    cin >> n1 >> n2 >> k1 >> k2;
    memset(dp, -1, sizeof(dp));


    int ans = 10;
    cout << ans << endl;

}