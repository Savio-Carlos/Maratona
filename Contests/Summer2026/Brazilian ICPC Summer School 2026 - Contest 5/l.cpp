#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)

signed main() {
    winton;
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &u : a) cin >> u; 
    sort(all(a));
    int m = a[n/2];
    int ans = 0;
    for (auto u : a) ans += abs(u - m);
    cout << ans << endl;
}
