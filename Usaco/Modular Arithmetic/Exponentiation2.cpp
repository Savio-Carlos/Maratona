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
const int MAX = 2e7+7;
const int MOD = 1e9+7;

/*
exponentiation (when evaluating x^n mod m, you can't store n as n mod m. 
If n turns out to be really huge, you need to calculate it modulo φ(m) instead,
 where φ stands for Euler's totient function. If m is prime, φ(m)=m−1.
 Note that this new modulus will then usually not be prime, thus "division" in it will not be reliable
*/

int fastExpo(int base, int exp, int m) {
    int res = 1;
    while(exp) {
        if (exp & 1) res = res * base % m;
        base = base * base % m;
        exp >>= 1;
    }
    return res%m;
}

void solve(){
    int a, b, c;
    cin >> a >> b >> c;
    int bc = fastExpo(b,c,MOD-1);
    cout << (fastExpo(a,bc,MOD)) << endl;
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--) solve();
}


