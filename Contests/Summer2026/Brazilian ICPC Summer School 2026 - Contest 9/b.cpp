#include <bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(0); cin.tie(0), cout.tie(0)
#define int long long
#define all(x) x.begin(), x.end()
#define debug(x) cout << x << " "; 
#define endl '\n'
 
signed main(){
    fastio;
    int n;
    cin >> n;
    vector<int> a(n);
    int mn=1e9;
    for(auto &u:a){
        cin >> u;
        mn = min(mn,u);

    }
    int sum = 0;
    for (int x : a) {
        if (x % mn != 0) {
            cout << -1 << endl;
            return 0;
        }
        int q = x / mn;
        if ((q & (q - 1)) != 0) {
            cout << -1 << endl;
            return 0;
        }
        sum += q;
    }

    int target = 1;
    while (target < sum) target <<= 1;
    int diff = target - sum;
    int ans = 0;
    ans = __builtin_popcountll(diff);
    cout << ans << endl;
}
