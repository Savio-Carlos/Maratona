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
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &u : a) cin >> u; 
    int ans = 1;
    for (int i = n-2; i >= 0; i--){
        if (a[i+1] % a[i] != 0){         
            int g = gcd(a[i+1], a[i]);
            int p = a[i]/g;
            ans = lcm(ans,p);
            a[i] /= ans;
        }
    }
    // vdebug(a);
    // debug(ans);
    cout << ans << endl;
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--)solve();
}
