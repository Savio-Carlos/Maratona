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

/*
pfx[i] divide todos os elementos ate i
sfx[i] divide todos os elementos depois de i
a[i] tem que ser um multiplo comum dos dois
entao a[i] = minimo multiplo comum dos dois = mmc 
*/

void solve(){
    int n;
    cin >> n;
    vector<int> pfx(n), sfx(n);
    for (auto &u : pfx) cin >> u;
    for (auto &u : sfx) cin >> u;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = lcm(pfx[i], sfx[i]);
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