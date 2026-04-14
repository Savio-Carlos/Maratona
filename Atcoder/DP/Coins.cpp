#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAXN = 1e5+7;
const int INF = LLONG_MAX;

ld dp[MAXN];

signed main(){
    winton;
    int n;
    cin >> n;
    vector<ld> coins(n);
    for (ld &u : coins) cin >> u;
    dp[0] = 1;
    for (auto u : coins){
        for (int i = n; i>=0 ; i--){
            dp[i] = dp[i]*(1-u) + dp[i-1]*u;
        }
    }
    ld ans = 0;
    for (int j = (n/2)+1; j <= n; j++){
        ans+=dp[j];
    }
    cout << fixed << setprecision(10) << ans << endl;
}
/*

        for (int j = 0; j <= n; j++){
            cout << dp[j] << " ";
        }
        cout << endl;
        
*/

