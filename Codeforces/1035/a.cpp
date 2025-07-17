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
const int INF = LLONG_MAX;

void solve(){
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    if (a > b){
        if ((a^=1LL) == b) {
        cout << 1 << endl;
        }
        else cout << -1 << endl;
        return;
    }
    int ans = 0;
    while (a < b){
        if (a&1){
            ans += min (x,y);
            a++;
        }
        else{
            ans += x;
            a++;
        }
    }
    cout << ans << endl;
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--)solve();
}
