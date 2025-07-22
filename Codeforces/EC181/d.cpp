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
const int MOD = 998244353;
const int INF = 0x3f3f3f3f3f3f3f3fLL;

int fastExpo(int base, int exp) {
    int r = 1;
    while(exp) {
        if (exp & 1) r = r * base % MOD;
        base = base * base % MOD;
        exp >>= 1;
    }
    return r;
}

int modInverse(int n) {
    return fastExpo(n, MOD - 2);
}

int modiv(int a, int b){
    
}

signed main(){
    winton;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> seg(m+1);
    vector<int> notprob(n), prob(n);
    for(int i = 0; i < n; i++){
        int l, r, p, q;
        cin >> l >> r >> p >> q;

        int invq = modInverse(q);
        int pi = (p * invq) % MOD;
        int chance = (((q - p) % MOD + MOD) % MOD * invq) % MOD;
        prob[i] = chance;
        notprob[i] = (pi * modInverse(chance)) % MOD;
        seg[r].push_back(i);
        seg[r].back() = (i<<20) | l;
    }

    vector<int> dp(m+1);
    dp[0] = 1;

    for(int i = 1; i <= m; i++){
        int sum = 0;
        for(int u : seg[i]){
            int c = u >> 20;
            int l = u & ((1<<20)-1);
            sum = (sum + dp[l-1] * notprob[c]) % MOD;
        }
        dp[i] = sum;
    }
    int prod = 1;
    for(int chance : prob) prod = (prod * chance) % MOD;
    int ans = (prod * dp[m]) % MOD;
    cout << ans << endl;
}