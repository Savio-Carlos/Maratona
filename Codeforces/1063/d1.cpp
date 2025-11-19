#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
// #define endl '\n'
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

void solve(){
    int n, q;
    cin >> n >> q;
    vector<int> mxr(n+1, -1);
    for (int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;
        mxr[l] = max(mxr[l], r);
    }
    int mx = 0;
    vector<pair<int,int>> intervals;
    for (int i = 1; i <= n; i++){
        if (mxr[i] > mx){
            mx = mxr[i];
            intervals.push_back({i,mx});
        }
    }
    debug(intervals);
    int l = 0, r = intervals.size()-1, ans = 0;
    while (l <= r){
        int mid = l + (r-l)/2;
        int a, b;
        auto [L, R] = intervals[mid];
        debug(L,R);
        cout << "? " << 1 << " " << R << endl;
        cin >> a;
        cout << "? " << L << " " << n << endl;
        cin >> b;

        debug(intervals[mid], a, b);
        ans = max(ans, min(a,b));

        if (a > b){
            r = mid-1;
        }
        else l = mid+1;
        debug(ans);
    }
    cout << "! " << ans << endl;

}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--) solve();
}
/*
6 6
1 2
2 4
3 3
4 6
5 5
6 6


1 2 3 4 5 6
? ? ? ? ? ?
5 3 0 1 2 4
___         -> 0
  _____     -> 2
    _       -> 1
      _____ -> 0
        _   -> 0
          _ -> 0

mex de um intervalo dentro de outro interval sempre vai ser menor ou igual que o mex do intervalo que o contem
faco trim nesses intervalos
quantos sobram? n intervalos

se eu faco uma query e a resposta e 0, entao e garantido que o 0 vai estar para o outro lado
e se eu fizer um bs pra construir a permutacao

5 3 0 1 2 4
4 6 = 0
1 3 = 1
111000
1 2 = 0
2 3 = 1
011000
...

ao inves de fazer duas queries posso fazer uma e manter o maximo encontrado, sempre procuro ir no range que a resposta e >= q o mx, menti e so pegar o maior

???000
?11000
?11000
mas ai deu errado
mas se eu tenho no maximo 1e4 intervalos
log2 disso = 14
logo uma solucao 2*14 = 28 < 30 passaria
logo posso fazer duas queries por vez
depois eu faco uma sparse table por que nao

3 2 1 0 4 5 6 8 7 9
? ? ? ? ? ? ? ? ? ?
1 5 = 5
5 10 = 0

5 ? ? ? ? 0 ? ? ? ? (futuramente tudo a direita do 0 vai ser 0)
1 3 = 0
3 5 = 2

existe o caso !!!! nao existe, nao existe o caso de um intervalo menor ter um mex melhor que um intervalo maior
mas eu tentar montar um vetor com o mex para cada cara n faz sentido

0 ? 2 ? 0 0 0 0 0
 eu consigo reconstruir o array original em logn querys? duvido
ok eu tenho n intervalos
tem como eu fazer um bs nesses intervalos e nao so no array?
ao inves de fazer do l ate mid e mid ate r, eu faco do 1 ate r e l ate n
ao fazer isso eu tiro separo todos os intervalos em dois sets diferentes, um set com os intervalos com l < meu L, e outro onde todos os intervalos tem um l maior que meu L
eu separo meus ranges por l e r e guardo num map
no final vai sobrar um range so

intervalos:
2 6
1 4
5 8
9 10

3 2 1 0 4 5 6 8 7 9
1 6 = 6 -> vou procurar em intervalos em que l < 2, posso talvez manter um set, vamos supor que vou para o 1,4
2 10 = 3

1 4 = 4
1 10 = 9 mas aqui o r passou do meu intervalo anterior, entao eu deveria limitar para r = 6?


guardo os ranges num vetor, ordenado pelo l de cada intervalo
faco uma bs nesse vetor pra saber em qual indice esta meu melhor intervalo
quando procurei no 2,6 (indice 2 no array), como a query do prefixo foi melhor, eu mudo meu r para 2, nesse caso r representa o indice maximo no vetor que vou procurar
*/