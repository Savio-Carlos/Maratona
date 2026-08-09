#include <bits/stdc++.h>
using namespace std;

#define endl '\n' 
#define winton ios_base::sync_with_stdio(0),cin.tie(0)
#define all(x) x.begin(), x.end()
#define ll long long

#define debug(x) cerr<<#x<<": " << x << endl;
#define vdebug(x) cerr << #x << ": "; for(auto i : x) cerr << i << " "; cerr << endl;

signed main(){
    winton;
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &u : a)cin >> u;
    sort(all(a));
    ll m = accumulate(all(a), 0LL);
    ll mm = m/2LL;
    ll ans = 0;

    auto check = [&](vector<ll> v) -> bool{
        ll s = 0;
        ll bro = m - a.back();
        for (auto u : v){
            s += u;
            bro -= u;
        }
        if (s <= bro) return true;
        else return false;
    };

    int tot = (1 << n);
    for (int mask = 0; mask < tot; mask++){
        vector<ll> cnt;
        ll sum = 0;
        for (int i = 0; i < n; i++){
            if (mask & (1<<i)){
                cnt.push_back(a[i]);
                sum += a[i];
            }
        }
        if (check(cnt)) ans = max(ans, sum+a.back());
    }
    cout << ans << " " << m-ans << endl;
}   
