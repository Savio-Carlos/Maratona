#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)

signed main() {
    winton;
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for (auto &u : a) cin >> u; 
    for (auto &u : b) cin >> u; 
    sort(all(a));
    sort(all(b));
    int i = 0, j = 0, ans = 0;
    while(i < n && j < m) {
        if (b[j] < a[i] - k) j++; 
        else if (b[j] > a[i] + k) i++; 
        else {
            ans++;
            i++;
            j++;
        }
    }
    cout << ans << endl;
}