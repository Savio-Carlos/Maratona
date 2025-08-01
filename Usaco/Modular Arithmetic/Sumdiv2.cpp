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

vector<int> factor(int n) {
    vector<int> primes;
    for (int p = 2; p * p <= n; ++p) {
        while (n % p == 0) {
            primes.push_back(p);
            n /= p;
        }
    }
    if (n > 1) 
        primes.push_back(n);
    return primes;
}


signed main(){
    winton;
    int a, b;
    cin >> a >> b;
    vector<int> primes = factor(a);
    map<int,int> freq;
    for (auto &p : primes) freq[p]++;
    // vdebug(primes);
    int ans = 1;
    for (auto [p,f] : freq){
        int prod2 = 1;
        for (int i = 1; i <= b*f; i++){
            if (a%f == 0) prod2 = (prod2 + fastExpo(p,i))%MOD; 
            //debug(i);
        }
        ans = (ans * prod2)%MOD;
    }

    cout << ans%MOD << endl;
}