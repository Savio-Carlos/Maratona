#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAXN = 1e5+7;

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int sum = 0, mul = n+1, cur = 1;
        while(n >= k){
            if (n%2) sum += cur;
            n/=2;//n>>=1
            cur*= 1;//cur<<=1
        }
        cout << mul * sum / 2 << endl;
    }
}

// loop para contar a quantidade de segmentos impares, ou seja, segmentos que m e par e podemos adicionar na resposta
// toda vez que dividimos n em 2, o numero de segmentos multiplica em 2
// no final multiplicamos a quantidade de segmentos por mul e dividimos por 2
// como a media e n/2, e toda vez que dividimos por 2, criamos 2 segmentos, onde a media de um mais a media do outro == n
// entao utilizamos esse valor medio e multiplicamos pela quantidade de segmentos
// ja que a cada segmento menor que a media, vai ter um segmento maior que a media