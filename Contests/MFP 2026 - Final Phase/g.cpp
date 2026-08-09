#include <bits/stdc++.h>
using namespace std;

#define endl '\n' 
#define winton ios_base::sync_with_stdio(0),cin.tie(0)
#define all(x) x.begin(), x.end()
#define int long long

#define debug(x) cerr<<#x<<": " << x << endl;
#define vdebug(x) cerr << #x << ": "; for(auto i : x) cerr << i << " "; cerr << endl;

signed main(){
    winton;
    int n, m, k;
    cin >> n >> m >> k;
    int range = k*2 + 1;
    vector<int> rivers(m);
    for (auto &u : rivers) cin >> u;
    rivers.push_back(n);
    sort(all(rivers));
    int ans = 0;
    int cur = 1;
    for (auto u : rivers){
        int sz = u - cur + 1;
        cur = u+1;
        ans += (sz + range - 1) / range;

    }   
    cout << ans << endl;
}
