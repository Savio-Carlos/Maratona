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
const int MAX = 1e7+7;

/*
F(4) = lcm(1,2,3,4) = 12
ate 4 temos 2 primos (2,3)
ate 12 temos 5 (2,3,5,7,11)
o lcm vai mudar sempre que encontrarmos um novo primo mas n so isso
como calcular quantos numeros distintos aparecem fazendo F(n)?
D(4) = 1 2 6 12 = 4
D(12) =  1 2 6 12 60 420 840 2520 27720 = 9

a resposta seria D(r) - D(l-1) = 9 - 3 = 6

D(12) 
1
2 -> 2 4 8
3 -> 3 9
5
7
11

o valor do lcm muda em todos esses numeros aqui

pegar todos os primos ate x, para cada um deles ir pegando as potencias dele e adicionando na contagem total

como pegar todos os primos ate 1e14?
segmented sieve para pegar todo o intervalo, ja que R-L <= 1e7

ai depois pega todos os primos ate a raiz de r e testa os seus expoentes, quando tiver entre l e r ans++

mas por que o lcm muda quando chegamos num quadrado perfeito (ou qualquer outro n^k)?

meu chute e que os outros numeros podem ser fatorados em varios primos diferentes com um expoente menor, 
quando encontramos um primo elevado a um expoente k maior que todos os outros vistos ate agora entao esse numero altera nosso lcm

quando fatoramos um numero pegamos os primos e sua maior potencia para cada um
quando fazemos lcm de 1...n o lcm se torna todos os maiores fatores primos que apareceram na fatoracao de todos os numeros 1...n
por ex se n = 15 entao lcm seria 360360
fatorando ele fica 2^3 * 3^2 * 5 * 7 * 11 * 13
ou seja todos os maiores fatores primos encontrados ate agora
e tambem isso garante que toda combinacao de fatores primos ate agora ja foi feita
como por ex 3*5 = 15, ja que o 3 e o 5 ja apareceram
por ex o 12 que e 2*2*3, mas ja temos 2*2*2*3 no nosso lcm, entao o lcm e um multiplo desse cara ja que inclusive nosso lcm e divisivel por 24
*/
vector<char> segmentedSieve(long long L, long long R) {
    // generate all primes up to sqrt(R)
    long long lim = sqrt(R);
    vector<char> mark(lim + 1, false);
    vector<long long> primes;

    for (long long i = 2; i <= lim; ++i) {
        if (!mark[i]) {
            primes.emplace_back(i);
            for (long long j = i * i; j <= lim; j += i)
                mark[j] = true;
        }
    }

    vector<char> isPrime(R - L + 1, true);
    for (long long i : primes){
        for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i){       
            isPrime[j - L] = false;
        }
    }
    if (L == 1) isPrime[0] = false;
    //para pegar os primos basta fazer i + L no vetor de isprime 
    return isPrime;
}

vector<int> sieve(int n) {
    vector<int> primes;
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = false;
    is_prime[1] = false;
    for (int p = 2; p * p <= n; ++p) {
        if (is_prime[p]) {
            for (int multiple = p * p; multiple <= n; multiple += p) {
                is_prime[multiple] = false;
            }
        }
    }
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

signed main(){
    winton;
    int l, r;
    cin >> l >> r;
    int ans = 1;

    vector<char> primeslr = segmentedSieve(l+1,r);
        for (int i = 0; i < (int)primeslr.size(); i++){
        if (primeslr[i]) ans++;
    }
    //debug(ans);

    vector<int> primes = sieve(sqrt(r));
    for (auto p : primes){
        int x = p;
        while (x * p <= r){
            if (x*p > l) ans++;
            x*=p;
        }
    }

    cout << ans << endl;

    // int mmc = 1;
    // for (int i = 1; i <= l; i++){
    //     cout << i << ": ";
    //     mmc = lcm(i,mmc);
    //     cout << mmc << endl;
    // }
}