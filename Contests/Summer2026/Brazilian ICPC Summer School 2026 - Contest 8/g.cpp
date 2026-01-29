
#include <bits/stdc++.h>
using namespace std;
 
#define fastio2 ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define dbg(x) cout << x << " "; 
#define endl '\n'

signed main(){
    fastio2;
    int l, g;
    cin >> l >> g;
    int ans = 0;
    for (int i = 0; i < g; i++){
        int p, d;
        cin >> p >> d;
        if (d) p = l-p;
        ans = max(p, ans);
    }
    cout << ans << endl;
}