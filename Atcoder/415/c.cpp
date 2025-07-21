#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
const int MAX = 2e5+7;
const int MOD = 1e9+7;

void solve(){
    int n;
    string s;
    cin >> n >> s;
    vector<char> dp((1<<n), 0);
    dp[0] = 1;
    for (int mask = 1; mask < (1<<n); mask++) {
        if (s[mask-1] == '1') {
            dp[mask] = 0;
        } else {
            for (int i = 0; i < (1<<n); i++) if (mask & (1<<i)) {
                if (dp[mask ^ (1<<i)]) {
                    dp[mask] = 1;
                    break;
                }
            }
        }
    }
    cout << (dp[(1<<n)-1] ? "Yes\n" : "No\n");
}

signed main() {
    winton;
    int t;
    cin >> t;
    while (t--) solve();
}