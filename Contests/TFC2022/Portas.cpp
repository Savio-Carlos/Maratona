#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAXS = 1e6+7;

signed main () {
    winton;
    int n, k; cin >> n >> k;
    vector<int> a(n+1,0);
    for (int i = 0; i < k; i++){
        int l, r, n;
        cin >> l >> r >> n;
        a[l-1] += n;
        a[r] -= n;
    }
    for (int i = 1; i < n+1; i++){
        a[i] += a[i-1];
    }
    int ans = 0, sum = 0;
    for (int i = 0; i < n; i++){
        sum = max(0LL, sum + a[i]);
        ans = max({ans, a[i], sum});
    }

    
    if (ans) cout << ans << endl;
    else {
        ans = -1e9;
        for (int i = 0; i < n; i++){
            ans = max(ans,a[i]);
        }
        cout << ans << endl;
    }
    
    //for (auto u : a) cout << u << " ";
}