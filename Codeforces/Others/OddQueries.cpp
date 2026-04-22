#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
using namespace std;
#define endl '\n'
#define int long long
const int MAXL = LLONG_MAX;

signed main(){_
    int t; cin >> t;
    while(t--){
        int n, q, sum = 0;
        cin >> n >> q;
        vector<int> arr(n), pfx(n+1);
        for (int i = 0; i < n; i++){ 
            cin >> arr[i];
            sum += arr[i];
            pfx[i+1] = arr[i];
            pfx[i+1] += pfx[i];
        }
        while(q--){
            int l, r, k;
            cin >> l >> r >> k;
            int diff = (pfx[r] - pfx[l-1]);
            if ((sum - diff+ k*(r-l+1)) % 2 != 0) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}