#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
using namespace std;
#define endl '\n'
#define int long long
const int MAXL = 1e6+7;

signed main() {_
    int n, d;
    cin >> n >> d;
    vector<int> points(n);
    for (auto &u : points) cin >> u;
    int ans = 0;
    int r = 0, l = 0;

    for (r = 0; r < n; r++) {
        while (points[r] - points[l] > d) {
            l++;
        }
        if (r-l+1 >= 3) {
            ans += (r-l) * (r-l - 1) / 2;
        }
    }
    cout << ans << endl;
}