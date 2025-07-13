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
const int INF = LLONG_MAX;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n), dp(n+3, 0);
    for (int &u : a) cin >> u;
    for (int i = n-1; i >= 0; i--) {
        int x = a[i] - dp[i+1];
        int y;
        if (i+1 < n) y = a[i] + a[i+1] - dp[i+2];
        else y = -INF;
        dp[i] = max(x, y);
    }
    vdebug(dp);
    int s = accumulate(all(a),0LL);
    cout << (s + dp[0])/2 << endl;
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--)solve();
}