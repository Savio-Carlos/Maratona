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
const int MAX = 1e5+7;
const int INF = INT_MAX;
const int MOD = 1e9+7;
/*
1 2 1
1 2 2
2 1 2
2 2 2
2 1 1
1 2 1
1 1 2

se eu quero uma matriz 2x2 e k = 2
entao pode ser
11 22
11 22

como uma 3x7 garante que eu sempre tenho essa matriz?
imagino que o harshith sempre tente equilibrar a quantidade de cada numero k na matriz, pois isso mimiza a chance de criar uma matriz com o mesmo numero igual
entao com certeza a matriz de tamanho NxM tem que ser maior igual que a*b*k (com excessao da matriz 1x1) 

no exemplo 1 
a*b*k = 8
n*m = 21

tentar encontrar primeiro o n depois o m
como precisamos de uma matriz 2x2, entao uma linha/coluna tem que ter pelo menos 2 do mesmo numero
uma linha de tamanho 3 garante que um dos numeros vai se repetir (temos so 1 e 2)
mas se k fosse 5, entao n teria que ser 6, mas ai eu so tenho garantia de um numero se repetindo(o que ta de boa ja que a = 2) mas como achar esse n? se a fosse 3 entao precisaria ter duas copias de cada numero k + 1
entao n = (a-1)*k + 1
1 2 3 4 5 2 
ok isso bate

entao como encontrar M?
tenho garantido que um dos valores ira com certeza se repetir A vezes em uma linha (ou coluna)
1 2 3 4 5 2
1 3 2 4 5 1
3 2 5 2 1 4
5 1 3 2 3 4
mas agora eu preciso que essa mesma combinacao se repita em M colunas
preciso que todas as combinacoes acontecam B-1 vezes
entao seria (numero de combinacos) * (b-1) + 1
numero de combinacoes = ?
para a = 2 b = 2 k = 2
n = 3
as combinacoes possiveis sao 
112
221
212
121
122
211

o que pode ser reescrito como
xxz
zxx
xzx

onde x e o numero que vai ser igual na linha, e z e qualquer outro numero
entao o total de combinacoes seria C(a,n)
ja que sao a numeros iguais numa linha de tamanho n
isso multiplicado por k pois qualquer um dos k valores pode ser o repetido
entao m = C(a,n) * k * (b-1) + 1
*/
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

long long combinations(int n, int k) {
    if (k < 0 || k > n) {
        return 0;
    }
    if (k == 0 || k == n) {
        return 1;
    }
    if (k > n - k) {
        k = n - k;
    }
    long long res = 1;
    for (int i = 1; i <= k; ++i) {
        res = res * (n - i + 1) / i;
    }
    return res;
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
    int a, b, k;
    cin >> a >> b >> k;
    int n = ((a-1)*k + 1) % MOD;
    int m = ((combinations_mod(n,a) % MOD)*k % MOD) *(b-1) % MOD;
    m += 1;
    cout << n%MOD << " " << m%MOD << endl;
}

signed main(){
    int t;
    cin >> t;
    while(t--) solve();
}