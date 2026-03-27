#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define dbg(x) cout << x << " "; 
#define endl '\n'

const int MOD = 1e9+7;
const int MAXN = 1e3+7;
int fat[MAXN], inv[MAXN];

int fastexpo(int a, int b){
    int res = 1;
    while(b > 0){
        if(b&1) res = (a*res)%MOD;
        a = (a*a)%MOD;
        b >>=1;
    }
    return res;
}

int comb(int a, int b){
    return (((fat[a] *inv[b])%MOD)*inv[a-b])%MOD; 
}

int modiv(int x){
    return fastexpo(x, MOD-2);
}

void solve(){
    int n, k; cin >> n >> k;
    vector<int> s(k+1, 0);
    for(int i = 1; i <= k; i++){
        int frac = modiv(i+1);
        int y = (fastexpo(1+n, i+1) - n - 1+MOD)%MOD;
        int sum = 0;
        for(int j = 1; j <= i-1; j++){
            sum = (sum + (comb(i+1, j)*s[j]%MOD))%MOD;
        }
        s[i] = (frac*((y - sum + MOD)%MOD))%MOD;
    }

    cout << s[k] << endl;
}

signed main(){
    fastio;
    fat[0] = fat[1] = 1;
    inv[0] = inv[1] = fastexpo(1, MOD-2);
    for(int i = 0; i < MAXN; i++){
        fat[i] = (fat[i-1]*i)%MOD;
        inv[i] = fastexpo(fat[i], MOD-2);
    }
    int t; cin >> t;
    while(t--){
        solve();
    }
}