#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

signed main(){
    fastio;
    int n;
    cin >> n;
    int dano=0;
    for(int i=0;i<n;i++){
        int x; cin >> x;
        if (x == 20) dano += 2;
        else if(x >= 15) dano++;
    }
    if(dano >= n) {
        cout << "O BRUTO FOI DERROTADO" << endl;
    } else cout << "O BRUTO ESTA VIVO TPK PARA O GRUPO" << endl;
    return 0;
}