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
const int INF = 0x3f3f3f3f3f3f3f3fLL;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> ai(n), b(n);
    for (auto &u : ai) cin >> u;
    for (auto &u : b) cin >> u;
    multiset<int> a(all(ai));
    vector<int> ans;
    for (auto u : b){
        int goal = m - u;
        //debug(goal);
        auto it = a.lower_bound(goal);
        if (it == a.end()) {
            it = a.begin();
        }
        //debug(*it);
        ans.push_back(*it);
        a.erase(it);
    }    
    int res = 0;
    for (int i = 0; i < n; i++){
        res += (ans[i] + b[i]) %m;
    }
    cout << res << endl;
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--) solve();
}   
