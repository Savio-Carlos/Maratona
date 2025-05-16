#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
using namespace std;
#define endl '\n'
#define int long long

signed main() {_
    int a, b;
    cin >> a >> b;
    int q1 = ceil(pow(a,1.0/6)), q2 = floor(pow(b,1.0/6));
    //cout << "q1 = " << q1 << " q2 = " << q2 << endl;
    int ans = max(0LL, q2-q1+1);
    cout << ans << endl;
}