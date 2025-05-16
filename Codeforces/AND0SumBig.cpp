#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
using namespace std;
#define endl '\n'
#define int long long
const int MOD = 1e9+7;

signed main() {_
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        int ans = 1;
        for(int i = 0; i < k; i++) ans = (ans*n)%MOD;
        cout << ans << endl;
    }
}