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
pegar os fatores primos de cada prato
guardar para cada primo a frequencia que os pratos divisiveis por ele aparecem
para cada query ver os primos que fatoram ele
seria facil se fosse so somar a frequencia desses primos mas pode ser que tenha dois primos que dividem o mesmo prato,
entao esse contaria duas vezes
para driblar isso aplicamos o principio de inclusao e exclusao de conjuntos
se o numero de numeros nesse conjunto for impar somamos seu valor, se for par diminuimos
um ex e o primeiro test case
pratos = 1 2 3 4 5 6
freq:
2 = 3
3 = 2
4 = 1
5 = 1
6 = 1

para a query 6, os fatores dele sao 2 e 3
mas ambos contam o prato 6 na sua frequencia
entao temos 3 conjuntos: (2) (3) (2,3)
ans = 3 + 2 - 1 = 4 (correto)
se ele tem alergia aos fatores 2 e 3 ele n pode comer 2,3,4,6, podendo comer so o 1,5

depois disso e so fazer fast expo para calcular as combinacoes com os pratos restantes
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