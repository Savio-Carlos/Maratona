#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
using namespace std;
#define endl '\n'
#define int long long
const int MAXL = 1e6+7;

signed main() {_
    int n, t;
    cin >> n >> t;
    vector<int> books (n);
    for (auto &i : books) cin >> i;
    vector<int> pfxsum (n+1);
    for (int i = 1; i <= n; i++){
        pfxsum[i] = books[i-1]+pfxsum[i-1];
    }
    int ans = 0;
    int l = 0;
    int cur = 0;
    for (int r = 0; r < n; r++) {
        cur += books[r];
        while (cur > t && l <= r) {
            cur -= books[l];
            l++;
        }
        ans = max(ans, r-l+1);
    }
    cout << ans << endl;

}