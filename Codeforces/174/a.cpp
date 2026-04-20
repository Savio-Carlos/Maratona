#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define int long long
#define ld long double

#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

void solve(){
    int p;
    cin >> p;
    int ans = 0;
    for (int x = 1; x < p; x++) {
        bool ok = true;
        int cur = 1;
        for (int k = 1; k <= p - 2; k++) {
            cur = (cur * x) % p;
            if (cur == 1) {
                ok = false;
                break;
            }
        }
        if (ok) ans++;
    }
    cout << ans << endl;
}

signed main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--) solve();
}