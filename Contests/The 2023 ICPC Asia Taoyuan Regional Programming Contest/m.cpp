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
    int n;
    cin >> n;
    vector<int> id(n), prio(n);
    for (auto &u : id) cin >> u;
    for (auto &u : prio) cin >> u;
    vector<tuple<int,int,int>> tasks(n);
    for (int i = 0; i < n; i++){
        tasks[i] = {prio[i], i, id[i]};
    }
    sort(all(tasks));
    for (auto [u,i,v] : tasks) cout << v << " ";
    cout << endl;
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--) solve();
}   
