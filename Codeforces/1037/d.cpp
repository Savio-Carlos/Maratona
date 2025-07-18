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
    int n, k;
    cin >> n >> k;
    vector<tuple<int,int,int>> a(n);
    for (auto &[l,r,real] : a){
        cin >> l >> r >> real;
    }
    sort(all(a));
    for (auto &[l,r,real] : a){
        if (k >= l && k <= r && real >= k){
            k = real;
        }
    }
    cout << k << endl;
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--)solve();
}
