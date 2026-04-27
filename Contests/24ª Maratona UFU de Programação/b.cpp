#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int long long
#define ld long double
#define endl '\n'

#define winton ios_base::sync_with_stdio(false),cin.tie(0)

/*
Etotal = maneiras de escolher |S| indices dentre os (n+m) * probabilidade desses indices formarem S
*/

const int MAX = 2000;
const int MOD = 1E9+7;

int fat[MAX], invfat[MAX];

int fastexpo(int base, int exp){
    int r = 1;
    while(exp){
        if(exp&1) r = r*base % MOD;
        base = base * base % MOD;
        exp >>= 1;
    }
    return r%MOD;
}

int modinv(int n){
    return fastexpo(n, MOD-2);
}

int modiv(int a, int b){
    return a * modinv(b) % MOD;
}

void build(){
    fat[0] = 1;
    for (int i = 1; i < MAX; i++) fat[i] = (fat[i-1] * i) % MOD;
    invfat[MAX-1] = modinv(fat[MAX-1]);
    for (int i = MAX-2; i >= 0; i--) invfat[i] = (invfat[i+1] * (i+1)) % MOD;
}

int comb(int n, int k){
    if (k > n || k < 0 || n < 0) return 0;
    return (((fat[n] * invfat[k]) % MOD) * invfat[n-k]) % MOD;
}

signed main(){
    winton;
    build();
    string s;
    int n, m;
    cin >> s >> n >> m;

    int ca = 0, cv = 0;
    for (auto c : s){
        if (c == 'V') cv++;
        else ca++;
    }
    int k = s.size();
    int tot = n+m;

    if (tot < k || ca > n || cv > m){
        cout << 0 << endl;
        return 0;
    }

    int ways = comb(tot, k);
    // cout << "ways: " << ways << endl;
    int rem = tot-k;
    int ra = n-ca;
    int rv = m-cv;

    int success = modiv(comb(rem, ra), comb(tot, n));
    cout << (ways * success) % MOD << endl;

}
