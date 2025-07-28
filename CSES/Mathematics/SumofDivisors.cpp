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

int pa(int n){
    return ((n*(n+1)))/2 % MOD;
}

signed main(){
    winton;
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i*i < n; i++){
        ans += (n/i * i);
        ans %= MOD;
        //debug(ans);
    }
    //debug(pa(n));
    //debug(pa(n/2));
    ans += (pa(n) - pa(n/2)) % MOD;
    cout << ans << endl;
}