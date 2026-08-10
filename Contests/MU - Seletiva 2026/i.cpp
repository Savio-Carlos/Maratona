#include <bits/stdc++.h>
using namespace std;

#define endl '\n' 
#define winton ios_base::sync_with_stdio(0),cin.tie(0)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int long long
#define ld long double

#define debug(x) cerr<<#x<<": " << x << endl;
#define vdebug(x) cerr << #x << ": "; for(auto i : x) cerr << i << " "; cerr << endl;

signed main(){
    winton;
    int n, q; 
    cin >> n >> q;
    vector<int> a(n);
    for (auto &u : a) cin >> u;
    vector<int> pfx(n+1);
    int cur = 0;
    for (int i = 1; i <= n; i++){
        cur += a[i-1];
        pfx[i] = cur;
    }
    while(q--){
        int l, r;
        cin >> l >> r;
        cout << pfx[r] - pfx[l-1] << endl;
    }
}