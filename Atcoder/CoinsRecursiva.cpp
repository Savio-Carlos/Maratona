#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAXN = 3*(1e3)+7;
const int INF = LLONG_MAX;

ld dp[MAXN][MAXN];
vector<ld> coins;
int n;
ld solve(int i, int h){
    if (i == n) return h >= ((n+1)/2) ? 1.0L : 0.0L;
    if (dp[h][i] != -1) return dp[h][i];
    return dp[h][i] = (solve(i+1, h+1) * coins[i]) + (solve(i+1, h) * (1-coins[i]));
}

signed main(){
    winton;
    cin >> n;
    for (int i = 0;i < n; i++){
        ld x;
        cin >> x;
        coins.push_back(x);
    }
    for (int i = 0; i < n + 1; i++){
        for (int j = 0; j < n + 1; j++){
            dp[i][j] = -1.0L;
        }
    }
    ld ans = solve(0,0);

    cout << fixed << setprecision(10) << ans << endl;
}