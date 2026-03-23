#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fastio ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)


signed main(){
    fastio;
    int q; cin >> q;
    while(q--){
        int x, k; cin >> x >> k;
        if(x >= k){
            cout << 1 << endl;
            continue;
        }else {
            int maior = x+x, segundo_maior = x, cnt = 2;
            while(maior < k){
                int aux = maior;
                maior = maior + segundo_maior;
                segundo_maior = aux;
                cnt++;
            }
            cout << cnt << endl;
        }
    }
}