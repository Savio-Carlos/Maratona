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
const int INF = LLONG_MAX;

/*
fatorar os pratos
ver quantos pratos tem para cada fator primo
depois fatorar cada cliente
ver quantos ele n pode comer
fazer fast expo
*/


int n, spf[MAX], pcnt[MAX], a[MAX], freq[MAX];

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

void build(){
    for (int i = 2; i < MAX; i+=2) spf[i] = 2;
    for (int i = 3; i < MAX; i+=2){
        if (spf[i] == 0){
            spf[i] = i;
            for (int j = i; j*i < MAX; j+=2){
                if (spf[i*j] == 0) spf[i*j] = i;
            }
        }
    }
}

void calc(){
    for (int i = 1; i < MAX; i++){
        for (int j = i; j < MAX; j+= i){
            pcnt[i] += freq[j];
        }
    }
}

vector<int> factorize(int x){
    vector<int> primes;
    while (x > 1){
        int p = spf[x];
        primes.push_back(p);
        while(x%p == 0) x/=p;
    }
    return primes;
}

signed main(){
    winton;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];    
        freq[a[i]]++;        
    } 
    build();
    calc();
    int q;
    cin >> q;
    while(q--){
        int x;
        cin >> x;
        vector<int> primes = factorize(x);
        int k = primes.size();
        int m = 0;
        for (int i = 1; i < (1<<k); i++){
            int prod = 1;

            for (int j = 0; j < k; j++){
                int pos = (1<<j);
                if (i&pos) prod *= primes[j]; 
            }
            int qtd = __builtin_popcount(i);
            if (qtd&1) m += pcnt[prod];
            else m -= pcnt[prod]; 
        }
        //debug(m);
        int ans = fastExpo(2, (n-m));
        cout << ans << endl;
    }
}