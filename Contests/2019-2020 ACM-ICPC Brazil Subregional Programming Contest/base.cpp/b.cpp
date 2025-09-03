#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'

signed main(){
    fastio;
    int n;
    cin >> n;
    vector<int> a(n);
    int mx = 0;
    for(auto &u : a) {
        cin >> u;
        mx = max(mx, u);
    }
    if (a[0] >= mx) {
        cout << "S\n";
    }
    else cout << "N\n";
}