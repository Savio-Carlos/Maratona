#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define dbg(x) cout << x << " "; 
#define endl '\n'

void solve(){
    int c, r, s;
    cin >> c >> r >> s;
    int mx = ((c+r+s-1)/s) - ((r+s-1)/s); 
    int mn = max(((c+r+s-1)/s) - r, 0LL);
    cout << mx << " " << mn << endl;
}

signed main(){
    fastio;
    int t;
    cin >> t;
    while(t--) solve();
}