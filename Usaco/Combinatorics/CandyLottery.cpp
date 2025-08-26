#include <bits/stdc++.h>
using namespace std;

using ld = long double;
using ll = long long;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(a) ((int)a.size())
#define endl '\n'

void debug_out(string s, int line) {cerr << endl; }
template<typename H, typename... T>
void debug_out(string s, int line, H h, T... t){
    do{
        cerr << s[0]; s = s.substr(1);
    }
    while (sz(s) and s[0] != ',');
    cerr << " = " << h;
    debug_out(s, line, t...);
}

#define DEBUG
#if defined(DEBUG)
    #define winton (void)0
    #define debug(...) debug_out(#__VA_ARGS__, __LINE__, __VA_ARGS__)
    #define vdebug(a) cerr << #a << " = ["; for(auto it = (a).begin(); it != (a).end(); ++it) cerr << *it << (next(it) == (a).end() ? "" : ", "); cerr << "]" << endl;
#else
    #define winton ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void)0
    #define vdebug(x) (void)0
#endif

const int MAX = 2e5+7;
const int MOD = 1e9+7;
const int INF = INT_MAX;
const ll LINF = LLONG_MAX;

/*
para todo i 1...k
qual a probabilidade desse meu i ser o maior valor?
ele vai ser o maior valor se comparado a todos os caras que vieram antes dele
por ex para n = 2 e k = 3
  1 2 3
1 1 2 3
2 2 2 3
3 3 3 3

a probabilidade do 1 ser maior e 1/9
a probabilidade do 2 ser maior e 4/9 
a probabilidade do 3 ser maior e 9/9

-> mesmo que o 2 so apareca 3 vezes, ele tambem vai ser maior que 1, entao a probabilidade total dele ser maior inclue todas as anteriores
o mesmo acontece pro 3

entao (i/k)^n eh a probabilidade dessa quantia i de doces ser a maior de todas
((i-1)/k)^n e a probabilidade de uma crianca receber menos que i doces
se a gente tirar o segundo do primeiro entao sobra so a possibilidade de uma crianca receber exatamente i doces
isso a gente multiplica por i que e a quantidade de doces

note que o (i/k)^n - ((i-1)/k)^n vai ser a quantidade de vezes que o i aparece na tabela
por ex para i = 3
(3/3)^2 = 1 (ou 9/9)
((3-1)/3)^2 = 4/9

9/9 - 4/9 = 5/9
se contar a quantidade de 3 na tabela, vera que e 5 realmente

/*/

ld fastExpo(ld base, int exp) {
    ld res = 1;
    while(exp) {
        if (exp & 1) res = res * base;
        base = base * base;
        exp >>= 1;
    }
    return res;
}
 
signed main(){
    winton;
    ld n, k;
    cin >> n >> k;
    ld ans = 0;
    cout << fixed << setprecision(6);
    // vector<int> test;
    for(int i = 1; i <= k; i++){
        ld ii = i;
        ans += ii * ((fastExpo((ii/k), n)) - (fastExpo((ld)(ii-1)/k, n)));
        debug(ans, i);
        // test.push_back(ans);
    } 
    // vdebug(test);
    
    cout << ans << endl;
}
