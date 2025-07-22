#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
const int MAX = 6607;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f3f3f3f3fLL;

int dp[2*MAX][MAX];

signed main(){
    winton;
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &u : a) cin >> u;
    dp[6600][0] = 1;
    for (int i = 0; i < n; i++){
        for (int k2 = k; k2 > 0; k2--){
            for (int sum = 0; sum <= MAX; sum++){
                if (sum-a[i] >= 0 && sum-a[i] <= 6600) dp[sum][k] += dp[sum-a[i]][k-1];
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= 2*MAX; i++){
        ans += dp[i][k-1];
    }
    cout << ans << endl;
}
