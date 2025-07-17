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

void solve(){
    int n;
    cin >> n;
    vector<int> pfx(n), sfx(n);
    for (auto &u : pfx) cin >> u;
    for (auto &u : sfx) cin >> u;
    bool pos = true;
    for (int i = 1; i < n; i++) {
        if (pfx[i-1] % pfx[i] != 0) pos = false;
        if (sfx[i] % sfx[i-1] != 0) pos = false;
    }
    if (pfx[n-1] != sfx[0]) pos = false;

    if (!pos) {
        cout << "NO\n";
        return;
    }

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        int g = gcd(pfx[i], sfx[i]);
        a[i] = (pfx[i] / g) * sfx[i];
    }
    //vdebug(a);

    vector<int> pfx2(n), sfx2(n);
    pfx2[0] = a[0];
    for (int i = 1; i < n; i++){
        pfx2[i] = gcd(pfx2[i-1], a[i]);
    }
    sfx2[n-1] = a[n-1];
    for (int i = n-2; i >= 0; i--){
        sfx2[i] = gcd(sfx2[i+1], a[i]);
    }
    if (pfx2 == pfx && sfx2 == sfx) cout << "YES\n";
    else cout << "NO\n";
}

signed main() {
    winton;
    int t;
    cin >> t;
    while (t--) solve();
}