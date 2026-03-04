#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define winton ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

const int MOD = 961;

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
    return (((a % MOD )* (fastExpo(b, MOD-2) % MOD)) % MOD);
}

signed main(){
    winton;
    // string s;
    // cin >> s;
    cout << "600" << endl;
    for (int mensagem = 1; mensagem <= 600; mensagem++){
        cout << 30 << " ";
        for (int j = 1; j <= 30; j++){
            for (int k = 0)
        }
        cout << endl;
    }
    // if (s == "send"){
    //     int x;
    //     cin >> x;
        
    // }
    // else {
    //     int a, b;
    //     cin >> a >> b;
        
    // }
}
