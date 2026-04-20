#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int long long
#define ld long double
#define endl '\n'

#define winton ios_base::sync_with_stdio(false),cin.tie(0)

signed main(){
    winton;
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &u:a) cin >> u;
    sort(all(a));
    int ans = 1e12;
    for (int i = 0; i < n/2; i++){
        ans = min(ans, a[i] + a[n-i-1]);
    }
    cout << ans << endl;
}

