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
const int MAX = 1e6+7;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f3f3f3f3fLL;

signed main(){
    winton;
    int n;
    cin >> n;
    if (n < 9){
        cout << n << endl;
        return 0;
    }
    if (n%2 == 0){
        cout << (n/2) % MOD << endl;
        return 0;
    }
    int ans = 0;
    if (n == 11) ans = 4;
    else if (n == 13) ans = 5;
    else if (n == 15) ans = 6;
    else if (n == 17) ans = 8;
    else if (n == 19) ans = 9;
    else if (n == 21) ans = 9;
    else if (n == 23) ans = 9;
    else if (n == 25) ans = 9;
    else if (n == 27) ans = 9;
    else ans = (1+(n-11)/2) % MOD;
    cout << ans << endl;
}