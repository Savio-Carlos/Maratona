#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define int long long
#define ld long double

namespace dbg {
    const char* const RESET     = "\033[0m";
    const char* const BOLD_BLUE = "\033[1;34m";
    const char* const YELLOW    = "\033[33m";
    const char* const BOLD_WHITE= "\033[1;37m";

    template<typename T1, typename T2>
    ostream& operator<<(ostream& os, const pair<T1, T2>& p) { return os << '{' << p.first << ", " << p.second << '}'; }

    template<typename T_container, typename T = typename enable_if<!is_same_v<T_container, string> && !is_same_v<T_container, string_view>, typename T_container::value_type>::type>
    ostream& operator<<(ostream& os, const T_container& v) {
        os << '{';
        bool first = true;
        for (const T& x : v) { os << (first ? "" : ", ") << x, first = false; }
        return os << '}';
    }

    void debug_out(string_view) { cerr << endl; }
    template<typename H, typename... T>
    void debug_out(string_view s, H h, T... t) {
        auto cpos = s.find(',');
        cerr << YELLOW << s.substr(0, cpos) << RESET << " = ";
        cerr << BOLD_WHITE << h << RESET;
        if constexpr (sizeof...(t) > 0) {
            cerr << ", ";
            auto nx = s.find_first_not_of(" \t\n\r", cpos + 1);
            debug_out(s.substr(nx), t...);
        } else {
            cerr << endl;
        }
    }
} 
using namespace dbg;

// #define DEBUG

#if defined(DEBUG)
    #define winton (void)0
    #define debug(...) cerr << BOLD_BLUE << "[" << __func__ << ":" << __LINE__ << "]" << RESET << " "; debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
    #define winton ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
    #define debug(...) (void)0
#endif

const int MOD = 1e9+7;
const int MAX = 1e5+7;

int fastExpo(int base, int exp) {
    int res = 1;
    while(exp) {
        if (exp & 1) res = res * base % MOD;
        base = base * base % MOD;
        exp >>= 1;
    }
    return res%MOD;
}

int modiv(int a, int b){
    return (a * fastExpo(b, MOD-2)) % MOD;
}

//toda vez que um numero aparece, essa mesa tem 0.5 de chance de receber i+1 frangos na prox instrucao
//mas tenho que considerar as mesas que ja visitei, todas elas tem chance de receber
//pra essas receberem, entao tem que ter continuado na mesma mesa desde a vez que o robo foi pra ela
//mas nisso eu ja teria somado todas os frangos que ele recebeu a cada instrucao, num mundo ideal
//toda vez que a mesa aparece eu duplico quantas cadeias possiveis em cada nivel termina nessa mesa
//para cada nivel, se eu souber quantas vezes cada mesa aparece naquele nivel eu consigo calcular a resposta
//                 1                         -> nivel 0 ignora
//        1                 1                -> nivel 1 ou ele vai pro um ou pede frango pro 1 (1 : 1, 2 : 0)
//    1       2         1       2            -> primeira vez que o 2 aparece (1 : 2, 2 : 0)
//  1   1   2   1     1   1   2   1          -> segunda vez que o 1 aparece (1: 2, 2 : 2)
// 1 3 1 3 2 3 1 3   1 3 1 3 2 3 1 3          -> independente do numero aqui, o numero de 1's que recebem frango... (1 : 6, 2 : 2)
//e se eu guardar a quantidade de ocorrencias de cada mesa na profundidade da instrucao
// ele recebe a (2^profundidade-1)/2 nos novos 
//mas eu ainda precisaria calcular pra cada cara a resposta dele 
// mas o numero de vezes que cada numero recebe frango se mantem, a n ser q um numero apareca dnv
// e se eu comecar de tras pra frente e for somando o proximo 
// o ev do proximo tambem e somado no meu ev, 


int fator[MAX], ans[MAX], aux[MAX];

signed main(){
    int n, q;
    cin >> n >> q;
    map<int, int> first;
    vector<int> a(q);
    for (int i = 0; i < q; i++){
        cin >> a[i];
        fator[i] = modiv(1LL, fastExpo(2LL, i+1));
    }

    for (int i = q-2; i >= 0; i--){
        int qtd = fastExpo(2LL, i);
        int f = fator[i+1];
        int ins = a[i+1];
        aux[i] = ((modiv(aux[i+1],2) % MOD) + ((f * qtd) % MOD * ins) % MOD )% MOD;
        debug(i, aux[i], qtd, f, ins);
    }
    for (int i = q-2; i >= 0; i--){
        ans[a[i]] = (ans[a[i]] + aux[i]) % MOD; 
    }

    int t1 = (modiv(1,8) + modiv(3,4) + modiv(5,8) + modiv(10,32) + 1) % MOD;
    int t2 = (modiv(1,8) + modiv(3,4) + modiv(1,8) + modiv(9,16)) % MOD;
    int t3 = (modiv(1,4) + modiv(1,4) + modiv(1,8)) % MOD;
    debug(t1, t2, t3);

    int t11 = (modiv(1,8) + modiv(3,4) + modiv(1,8) + modiv(1,16) + 1) % MOD;
    int t12 = (modiv(8,16) + modiv(8,32)) % MOD;
    debug(t11, t12, (t11 + t12) % MOD);
    debug(ans[1]);

    

    // ans[1] = (ans[1] + ans[a[0]] + (modiv(1,2) * a[0]) % MOD) % MOD;//isso ta errado
    for (int i = 0; i < q; i++){
        ans[1] = (ans[1] + (a[i] * fator[i]) % MOD) % MOD;
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << endl;
}