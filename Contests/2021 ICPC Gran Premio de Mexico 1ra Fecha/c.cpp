#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define winton ios_base::sync_with_stdio(0),cin.tie(0)

const int MAX = 1e6+7;

vector<bool> is_prime(MAX + 1, true);
vector<int> pfx(MAX, 0);

void sieve(){
    
    is_prime[0] = 0;
    is_prime[1] = 0;
    for (int p = 2; p*p < MAX; ++p){
        if (is_prime[p]){
            for (int m = p*p; m < MAX; m += p){
                is_prime[m] = 0;
            }
        }
    }
    for (int i = 1; i < MAX; i++){
        pfx[i] = pfx[i-1] + is_prime[i];
    }
}

signed main(){
    winton;
    sieve();
    int t;
    cin >> t;
    while(t--){
        int i, j;
        cin >> i >> j;
        cout << pfx[j] - pfx[i-1] << endl;
    }
    
}
