#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long
#define vi vector<int>
#define pb push_back
const int MAXL = 1e9+7;

void solve(){
    int n, k; cin >> n >> k;
    vi a(n);
    for (auto &i : a) cin >> i;
    sort(all(a));
    if (k >= 3){cout << "0" << endl; return;}
    int mini = a[0];
    for (int i = 0; i < n-1; i++){
        mini = min(mini, (a[i+1]-a[i]));
    }
    if (k == 1){cout << mini << endl; return;}

    vi diffs;
    int ans = mini;
    for (int i = 0; i < n-1; i++){
        for (int j = i+1; j < n; j++){
            diffs.pb(abs(a[i]-a[j]));
        }   
    }
    sort(all(diffs));
    for (int i = 0; i < n; i++){
        auto u = lower_bound(all(diffs), a[i]);
        if (u != diffs.end()) ans = min(abs(*u - a[i]), ans);
        if (u != diffs.begin()) ans = min(abs(*(u-1) - a[i]), ans);
    }

    cout << ans << endl;
    return;
}

signed main(){_
    int t; cin >> t;
    while(t--) solve();
}