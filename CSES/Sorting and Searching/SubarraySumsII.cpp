#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long
const int MAXL = 1e5+7;
signed main() {_
    int n, x;
    cin >> n >> x;
    int sum = 0, ans = 0;
    map<int, int> pfx;
    pfx[0] = 1;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        sum += a;
        ans += pfx[sum - x];
        pfx[sum]++;
    }
    cout << ans << endl;
}
