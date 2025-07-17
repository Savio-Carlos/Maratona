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
const int MAX = 2e5+7;
const int MOD = 1e9+7;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> dp1(n+1), dp2(n+1);
    dp1[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (auto &u : dp2) u = 0;
        for (int j = 0; j <= i; j++) {
            int x = 0;
            if (j > 0) x = dp1[j-1];
            if (j <= i-1) x = (x + (n - i + 1) * (j + 1) % m * dp1[j] % m) % m;
            dp2[j] = x;
        }
        swap(dp1, dp2);
    }
    int ans = 0;
    for (int j = 0; j <= n; j++) {
        ans = (ans + dp1[j]) % m;
    }
    cout << ans << endl;
}

signed main() {
    winton;
    int t;
    cin >> t;
    while (t--) solve();
}