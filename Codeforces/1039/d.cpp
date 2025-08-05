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
const int MAX = 2e5+7;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f3f3f3f3fLL;

/*
sempre somo n na resposta
como max(ai,ai+1) > ai+2 eu sei que minha lds aumenta a cada 2 caras no maximo
3 2 1
i = 2
best = 2 (essa sequencia de tamanho 2 que e uma lds)

i = 3
best = 5 (temos mais uma sequencia de tamanho 2 e uma sequencia de tamanho 3)

toda vez que encontramos a[i] < a[i-1] aumentamos o tamanho de todas as lds ja encontradas

estamos sempre somando na resposta a soma de todos os subarrays ja encontrados e que terminam em i
se a[i] > a[i-1] entao nao aumentamos nossa lds, entao so aumentamos um no best e somamos na resposta
isso pq a lds em cada intervalo se manteve igual a iteracao passada, mas criamos um novo intervalo, e ele tem tamanho lds = 1 ja que a[i] > a[i-1]

se a[i] < a[i-1], entao aumentamos em i o best
isso pq para cada intervalo ja calculado, a lds nele vai aumentar em um, isso pq estamos considerando todos os intervalos que terminam em i

e como se a cada novo numero a gente atualizasse todos os intervalos existentes, 
se o numero nao faz parte da lds entao eles se mantem igual(adiciona um que e o novo intervalo a[i-1]...a[i])
se o numero faz parte da lds entao pega todos os intervalos e aumenta em 1
se i = 5 entao temos 4 intervalos + o novo intervalo a[i-1]...a[i], e dai adiciona isso no best 

e sempre soma na resposta 
*/

void solve(){
    int n;
    cin >> n;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int best = 0, ans = 0;
    for (int i = 2; i <= n; i++){
        if (a[i] < a[i-1]) best += i;
        else best++;
        ans += best;
    }
    cout << ans+n << endl;
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--)solve();
}
