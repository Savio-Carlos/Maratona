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
const int MOD = 998244353;
const int INF = 0x3f3f3f3f3f3f3f3fLL;

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
    if (k < 0 || k > n) {
        return 0;
    }
    if (k == 0 || k == n) {
        return 1;
    }
    if (k > n / 2) {
        k = n - k;
    }
    int numerator = 1;
    for(int i = 0; i < k; i++) {
        numerator = (numerator * (n - i)) % MOD;
    }
    int denominator = 1;
    for(int i = 1; i <= k; i++) {
        denominator = (denominator * i) % MOD;
    }
    return (numerator * modInverse(denominator)) % MOD;
}

void solve(){
    int n, x;
    cin >> n >> x;
    if (n > x){
        cout << 0 << endl;
        return;
    }
    
    

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--)solve();
}
