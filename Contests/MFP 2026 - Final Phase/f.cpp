#include <bits/stdc++.h>
using namespace std;

#define endl '\n' 
#define winton ios_base::sync_with_stdio(0),cin.tie(0)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ll long long
#define ld long double

#define debug(x) cerr<<#x<<": " << x << endl;
#define vdebug(x) cerr << #x << ": "; for(auto i : x) cerr << i << " "; cerr << endl;


signed main(){
    winton;
    int n;
    cin >> n;
    vector<ld> p(n);
    for (auto &u : p){
        cin >> u;
        u /= 100.0;
    } 
    int tot = (1 << n);
    vector<ld> prob(tot, 1.0);
    vdebug(p);
    for (int mask = 0; mask < tot; mask++){
        for (int i = 0; i < n; i++){
            if (mask & (1 << i)) prob[mask] *= p[i];
            else prob[mask] *= (1.0 - p[i]);
        }
    }
    sort(rall(prob));

    ld ans = 0;
    for (int mask = 1; mask <= tot; mask++){
        ans += mask * prob[mask-1];
    }
    cout << fixed << setprecision(10) << ans << endl;
}
