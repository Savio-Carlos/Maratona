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

int modinverse(int n) {
    return fastExpo(n, MOD - 2);
}

int modiv(int a, int b){
    return (a * modinverse(b))%MOD;
}

signed main(){
    winton;
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> segs(m+1);
    int totn = 1;
    for(int i = 0; i < n; i++){
        int l, r, p, q;
        cin >> l >> r >> p >> q;
        int pr = modiv(p,(q-p));
        segs[r].push_back({l,pr});
        totn = (totn * modiv(q-p,q)) % MOD;
    }

    vector<int> dp(m+1);
    dp[0] = 1;

    for (int r = 1; r <= m; r++){
        for (auto [l, pr]: segs[r]){
            dp[r] += dp[l-1] * pr;
            dp[r] %= MOD;
        }
    }
    cout << (totn * dp[m]) % MOD << endl;
}