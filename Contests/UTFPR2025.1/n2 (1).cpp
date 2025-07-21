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
const int MAX = 1e5+7;
const int INF = LLONG_MAX;
const int MOD = 998244353;

const int M = 998244353;
const int INV2 = 499122177;
const int INV6 = 166374059;

int mod_mul(int x, int y) {
    return (x % M) * (y % M) % M;
}

signed main() {
    winton;
    int a, b;
    cin >> a >> b;
    int A = a % M, B = b % M;
    int rects = mod_mul( mod_mul(A, (A+1)%M) * INV2 % M,mod_mul(B, (B+1)%M) * INV2 % M );
    debug(rects);
    int t = min(a,b) % M;
    int S1 = mod_mul( mod_mul(t, (t-1+M)%M), INV2 );
    debug(S1);
    int S2 = mod_mul( mod_mul(mod_mul(t, (t-1+M)%M), ((2*t-1+M)%M)), INV6 );
    debug(S2);
    int squares = ((mod_mul(t, mod_mul(A,B))- mod_mul((A+B)%M, S1)+ S2) % M + M) % M;
    debug(squares);

    int ans = (rects - squares + M) % M;
    cout << ans << "\n";
    return 0;
}