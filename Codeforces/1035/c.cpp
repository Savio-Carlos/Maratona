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

int pot(int x) {
    int b = 63 - __builtin_clzll(x);
    return 1LL << (b + 1);
}

void solve(){
    int n, l, r, k;
    cin >> n >> l >> r >> k;
    if (n&1){
        cout << l << endl;
        return;
    }
    if (n < 4){
        cout << -1 << endl;
        return;
    }
    int x = pot(l);
    if (x > r) {
        cout << -1 << endl;
        return;
    }
    if (k <= n-2){
        cout << l << endl;
    }
    else cout << x << endl;
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--)solve();
}
