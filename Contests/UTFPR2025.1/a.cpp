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
const int MAX = 1e5+7;
const int INF = INT_MAX;

signed main(){
    int n;
    cin >> n;
    vector<pair<int,int>> times(n);
    for (auto &[v,u] : times) cin >> u >> v;
    sort(all(times));
    int ans = 1, cur = 0;

    //for (auto &[u,v] : times) cout << u << " " << v << endl;

    for (int i = 1; i < n; i++){
        if (times[i].second >= times[cur].first){
            ans++;
            cur = i;
            //debug(i);
        }
    }

    cout << ans << endl;
}