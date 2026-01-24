#include <bits/stdc++.h>
using namespace std;

#define int long long
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)

const int MOD = 1e9+7;

int fastExpo(int base, int exp) {
    int res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

int modInverse(int n) {
    return fastExpo(n, MOD - 2);
}
int combinations_mod(int n, int k) {
    if (k < 0 || k > n)  return 0;
    if (k == 0 || k == n) return 1;
    if (k > n / 2) k = n - k;
    int numerator = 1;
    for(int i = 0; i < k; i++) numerator = (numerator * (n - i)) % MOD;
    int denominator = 1;
    for(int i = 1; i <= k; i++) denominator = (denominator * i) % MOD;
    return (numerator * modInverse(denominator)) % MOD;
}

signed main(){
    winton;
    int n;
    cin >> n;
    if (n&1){cout<<0<<endl; return 0;}
    int ans = (combinations_mod(n, n/2) - combinations_mod(n, (n/2)-1) + MOD) % MOD;
    cout << ans << endl;
}
