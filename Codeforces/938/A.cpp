#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
using namespace std;
#define endl '\n'
#define int long long

signed main() {_
    int t; cin >> t;
    while(t--){
        int n, a, b;
        cin >> n >> a >> b;
        int ans;
        if (n%2 == 0) {
            ans = min (n*a, n*b/2);
        }
        else {
            ans = min(n*a, ((n/2) * b) + a);
        }
        cout << ans << endl;
    }
}
