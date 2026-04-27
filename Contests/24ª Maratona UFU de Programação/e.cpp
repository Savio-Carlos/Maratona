#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int long long
#define ld long double
#define endl '\n'

#define winton ios_base::sync_with_stdio(false),cin.tie(0)

/*

vou dividindo as duas coordenadas por 2 (>>= 1 no caso) e vendo se elas param num quadrante que
 inverte ou nao as cores de acordo com o tamanho atual da matriz
n posso tratar como numero
*/

signed main(){
    winton;
    int n;
    string s1, s2;
    cin >> n >> s1 >> s2;

    int inv = 0;

    for (int i = 0; i < n; i++){
        if (s1[i] != s2[i]) inv++;
    }
    // cout << "inv: " << inv << endl;
    if (inv%2 == 0) cout << "BRANCO" << endl;
    else cout << "AZUL" << endl;
}
