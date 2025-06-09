#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAX = 2e5+7;
const int INF = INT_MAX;

/*
numero total de 0s no intervalo + numero de 1s fora do intervalo
mas como achar o intervalo otimo?
ai = numero de 0s ate i
bi = numero de 1s ate i
ci = ai-bi, ou seja, a diferenca entre o numero de 0s e 1s ate o ponto i
achar o minimo de cr - cl
isso significa achar o intevalo l r onde a diferenca entre o numero de 0s e 1s e a maior possivel
isso pq dessa maneira pegamos uma quantidade grande de 1s e minimizamos os 0s, ou pegamos muitos 0s e minimizamos os 1s
guardamos o valor maximo pois ele representa o l, ou seja, o local onde temos a maior quantidade de leading 0s e menos 1s

fazer c[i] - maximo calcula a diferenca entre o numero de 0s - 1s atual, excluindo os leading 0s
arr  = 0 0 0 1 0 1 1 1 1 0 0 1 1 1 1 1 
c[i] = 1 2 3 2 3 2 1 0-1 0 1 0-1-2-3-4  -> guarda a quantidade de 1s em comparacao a 0s ate i
max  = 1 2 3 3 3 3 3 3 3 3 3 3 3 3 3 3  -> guarda a maior quantidade de 0s a esquerda do intervalo
res  = 0 0 0-1 0-1-2-3-4-3-4-3-4-5-6-7

A ideia é que, para minimizar Cr−1 − Cl−1, precisamos:
Que Cr−1 (o excedente de zeros no final do intervalo) seja o menor possível.
E que C l−1 (o excedente de zeros no início do intervalo) seja o maior possível.

nesse exemplo pegariamos 
0001011110011111
   L           R

no final fazemos sum - res para considerar os 1's que estao fora do melhor intervalo

*/

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n >> s;
        vector<int> c(n + 1);
        for (int i = 0; i < n; ++i) {
            c[i + 1] = c[i] + (s[i] == '0' ? 1 : -1);
        }
        //for (auto i : c) cout << i << " ";
        //cout << endl;

        int sum = count(s.begin(), s.end(), '1');
        int ma = 0;
        int res = 0;
        for (int i = 0; i <= n; ++i) {
            res = min(res, c[i] - ma);
            ma = max(ma, c[i]);
            //cout << i << ": " << res << " " << ma << endl; 
        }
        cout << sum + res << endl;
    }
}