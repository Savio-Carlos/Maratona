#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAXN = 1e5+7;

int n, dp[MAXN][4], h[MAXN][4];


signed main(){
    winton;

    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> h[i][1] >> h[i][2] >> h[i][3];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= 3; j++){
            for (int k = 1; k <= 3; k++){
                if (k == j) continue;
                dp[i][j] = max(dp[i][j], dp[i-1][k] + h[i][j]);
            }
        }
    }
    for (int i = 1; i <= 3; i++){
        ans = max(ans, dp[n][i]);
    }
    cout << ans << endl;
}

/*
int solve(int idx, int d, int w){
    if (d > n) return w;
    int ans = 0;
    for (int i = 0; i < 3; i++){
        if (i == idx) continue;
        ans = max(ans, solve(i, d+1, w + h[i][d]));
    }
    //cout << "idx: " << idx << " d: " << d << " ans: " << ans << endl;
    return ans;
}
*/