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
    base %= MOD;
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
    ifstream cin("sumdiv.in");
    ofstream cout("sumdiv.out");
    int a, b;
    cin >> a >> b;
    if (!b){
        cout << 1 << endl;
        return 0;
    }
    vector<int> primes = factor(a);
    map<int,int> freq;
    for (auto &p : primes) freq[p]++;
    //vdebug(primes);
    int ans = 1;
    for (auto [p,f] : freq){
        if (p % MOD == 1){//se p%MOD == 1 entao nao tem como calcular p-1 para o denominador la embaixo
            //mas ainda assim p==1 entao para qualquer expoente f, a resposta vai ser um
            //entao fazemos um somatorio de 1 ate f*b 
            int prod = (((b%MOD)*(f%MOD))%MOD + 1)%MOD;
            ans = (ans * prod)%MOD;
        }
        else {            
            int exp = (f % (MOD-1)) * (b % (MOD-1)) % (MOD-1);
            exp = (exp+1) % (MOD-1);
            //debug(exp);
            int num = (fastExpo(p,exp)-1 + MOD) % MOD;
            int den = (p-1 + MOD) % MOD;
            int prod = modiv(num,den)%MOD;
            ans = (ans * prod)%MOD;
        }
    }
    cout << ans%MOD << endl;
}