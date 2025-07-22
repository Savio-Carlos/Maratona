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
contar quantos numeros de 0 ate r e 0 ate l tem os primos (2,3,5,7,) que sao not good
usar bitmask apara fazer as combinacaoes desse primo e tirar do total 
*/

int funcao(int n){
    int primes[] = {2,3,5,7};
    int k = 4;
    int ans = n;
    for (int i = 1; i < (1<<k); i++){
        int p = 1;
        int cnt = __builtin_popcount(i);
        for (int j = 0; j < k; j++){
            if ((1<<j) & i){
                p*=primes[j];
            }
        }
        int d = n/p;
        if (cnt&1) ans -= d;
        else ans+=d;
    }
    return ans;
}

void solve(){
    int l, r;
    cin >> l >> r;
    cout << funcao(r) - funcao(l-1) << endl;
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--)solve();
}
