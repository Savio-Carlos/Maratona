#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
using namespace std;
#define endl '\n'
#define int long long
const int MAXL = 1e6+7;

signed main() {_
    int t; cin >> t;
    while(t--){
        long double x, y, k;
        cin >> x >> y >> k;
        long double tt = (((k*y) + (k))-1)/(x-1);
        int ans2 = ceil(tt) + k;
        cout << ans2 << endl;
    }
}