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

void solve(){
    int a, b, k;
    cin >> a >> b >> k;
    int mx = max(((a+k-1)/k),((b+k-1)/k));
    if (k >= a && k >= b || a == b) cout << 1 << endl;
    else if (gcd(a,b) >= mx) cout << 1 << endl;
    else cout << 2 << endl;
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--)solve();
}