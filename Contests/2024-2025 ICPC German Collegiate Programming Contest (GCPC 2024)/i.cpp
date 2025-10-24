#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

/*
there will be at most 4000 queries
worst case scenario, 4000 waves
4e4*4e4 =1e7
we can just check for each point how many are here
how do we know if there's a wave that is here? 
p, l, a
p+l <= P, then there is a wave here

*/

void solve(){
    int n, m; cin >> n >> m;

    vector<tuple<int, int, int>> waves;
    for(int i = 0; i < n; i++){
        char op; cin >> op;
        if(op == '!'){
            int p, l, a; cin >> p >> l >> a;
            l--;
            waves.push_back({p, l, a});
        }else{
            int P; cin >> P;
            int ans = 0;
            for(auto [p, l, a] : waves){
                if(p <= P && p+l >= P){
                    int val = ((P-p)%4);
                    //cout << "wave " << p << " " << l << " " << a << " " << val << endl;
                    if(val == 1 || val == 3) continue;
                    else if(val == 0) ans += a;
                    else ans -= a;
                }
            }
            cout << ans << endl;
        }
    }
}

signed main(){
    int t;
    //cin >> t;
    t = 1;
    while(t--){
        solve();
    }
}