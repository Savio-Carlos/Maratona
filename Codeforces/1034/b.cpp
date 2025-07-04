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
const int MOD = 1e9+7;
const int INF = LLONG_MAX;

void solve(){
    int n, j, k, mx = 0;
    cin >> n >> j >> k;
    int p;
    for (int i = 1; i <= n; i++){
        int a; cin >> a;
        mx = max(a,mx);
        if (i == j){
            p = a;
        } 
    }
    if (k == 0)cout << "NO" << endl;
    else if (k == 1 && p != mx) cout << "NO" << endl;
    else cout << "YES" << endl; 
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--) solve();
}