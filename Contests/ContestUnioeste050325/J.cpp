#include <bits/stdc++.h>
using namespace std;
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long
#define ld long double
const int MOD = 1e9+7;

signed main() {
    winton
    int n, q; cin >> n >> q;
    vector<int> a(n);
    vector<int> pfx(n+1,0);
    vector<int> mult(n+1, 0);
    for (auto &i : a) cin >> i;
    pfx[0] = 0;
    for (int i = 1; i <= n; i++){
        pfx[i] = a[i-1];
        pfx[i] += pfx[i-1]%MOD;
    }
    for (int i = 1; i <= n; i++){
        mult[i] = mult[i-1] + (a[i-1]*a[i-1]);
    }

    while (q--){
        int l, r;
        cin >> l >> r;

        int sum = (pfx[r] - pfx[l - 1] + MOD) % MOD;
        int multsum = (mult[r] - mult[l - 1] + MOD) % MOD;
        int ans = (sum * sum % MOD - multsum + MOD) % MOD;
        ans = (ans * ((MOD + 1) / 2)) % MOD;

        cout << ans << endl;
    }

}
