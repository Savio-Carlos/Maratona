#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)

signed main () {
    winton;
    int t;
    cin >> t;
    while(t--){            
        int n, k;
        cin >> n >> k;
        map<int, int> mp;
        for (int i = 0; i < n; i++){
            int m; cin >> m;
            int mod = m%k;
            if (mod != 0){
                mod = k - mod;
                mp[mod]++;
            }  
        }
        //for (auto [u,v] : a) cout << u << " " << v << endl;
        int ans = 0;
        for (auto &u : mp){
            int resto = u.first;
            int cnt = u.second;
            //cout << resto << " " << cnt << endl;
            ans = max(ans, resto + k*(cnt-1));
        }
        if (!(ans == 0)) ans++;
        cout << ans << endl;
    }
}