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
const int MAX = 1e6+7;
const int MOD = 1e9+7;

int fastExpo(int base, int exp) {
    int r = 1;
    while(exp) {
        if (exp & 1) r = r * base % MOD;
        base = base * base % MOD;
        exp >>= 1;
    }
    return r;
}

int modinverse(int n) {
    return fastExpo(n, MOD - 2);
}

int modiv(int a, int b){
    return (a * modinverse(b))%MOD;
}


int pa(int n, int a1){
    // debug(n);
    n%=MOD;
    a1%=MOD;
    // debug(a1);
    return modiv(((n-a1+1)*(a1+n)%MOD),2LL);
}

int pa2(int n){
    return ((n+1) * n)/2;
}

signed main(){
    winton;
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i*i <= n; i++){
        ans += (n/i * i);
        ans %= MOD;
    }
    for (int i = 1; i*i+i <= n; i++){
        int x = pa(n/i, n/(i+1)+1);
        ans += (x) * i;
        ans %= MOD;
        //debug(x);
        //debug(i);
    }
    
    //debug(ans);
    cout << ans%MOD << endl;
    
    // //brute que funciona
    // int brute = 0;
    // for (int i = 1; i <= n/2; i++){
    //     brute += (n/i * i);
    //     brute %= MOD;
    //     //debug(brute);
    // }

    // brute += (pa2(n) - pa2(n/2)) % MOD;
    // debug(brute);
}