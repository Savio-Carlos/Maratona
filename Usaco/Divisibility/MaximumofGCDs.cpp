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

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<map<int,int>> best(n);
    vector<int> ans(n);
    int mx = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        best[i][a[i]] = 1;
        mx = max(a[i], mx);
    }
    // debug(mx);
    //ans[0] = mx;
    for (int i = 1; i < n; i++){
        for (auto [gg, size] : best[i-1]){
            int g = gcd(gg,a[i]);
            best[i][g] = max(best[i][g], size+1);
        }
    }
    for (int i = 0; i < n; i++){
        for (auto [g, size] : best[i]){
            // debug(size-1);
            // debug(g);
            ans[size-1] = max(ans[size-1],g);
            // vdebug(ans);
        }
    }
    // for (int i = 0; i < n; i++){
    //     cout << i << ": ";
    //     for (auto [a,c] : best[i]){
    //         cout << "{" << a << " : " << c << "}" << "   ";
    //     }
    //     cout << endl;
    // }
    for (auto u : ans) cout << u << " ";
    cout << endl;
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--) solve();
}