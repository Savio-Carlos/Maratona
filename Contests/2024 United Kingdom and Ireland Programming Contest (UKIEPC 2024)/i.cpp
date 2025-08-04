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

signed main(){
    winton;
    int n, m;
    cin >> n >> m; 
    // a1 = b1 = 1, isso da um ratio de 1 usando so uma questao
    // c1 = d1-1, isso da um ratio de 0.99 usando quantas questoes eu quiser
    // so resta calcular para as restantes das categorias
    
    int d1 = m - 3*(n-1);
    //debug(d1);
    int c1 = d1-1;
    cout << 1 << " " << 1 << " " << c1 << " " << d1 << endl;
    for (int i = 0; i < n-2; i++){
        cout << 1 << " " << 2 << " " << 1 << " " << 3 << endl;
    }
    int bn = m-((n-2)*2)-1;
    int dn = m-d1-((n-2)*3);
    // debug(bn);
    // debug(dn);
    int an = (c1 - 1);
    int cn = 1;
    // debug (an); 
    // debug (cn); 
    cout << an << " " << bn << " " << cn << " " << dn << endl;
}