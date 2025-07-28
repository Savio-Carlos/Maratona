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

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int mmc(int a, int b) {
    return a / gcd(a, b) * b;
}

signed main(){
    winton;
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &u : a) cin >> u;
    vector<int> pfx(n+1, 0), sfx(n+1, 0);
    for (int i = 1; i <= n; i++){
        pfx[i] = gcd(a[i-1], pfx[i-1]);
    }
        for (int i = n-1; i >= 0; i--){
        sfx[i] = gcd(a[i], sfx[i+1]);
    }

    //vdebug(pfx);
    //vdebug(sfx);
    int ans = 1;
    for (int i = 0; i < n; i++){
        ans = lcm(ans, gcd(pfx[i], sfx[i+1]));
       // debug(ans);
    }
    cout << ans << endl;

}