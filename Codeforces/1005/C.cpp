#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
using namespace std;
#define endl '\n'
#define int long long
const int MAXL = 1e5+7;

signed main() {_
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> arr(n), pfx(n), sfx(n);
        for (int &i : arr) cin >> i;

        if (arr[0] > 0) pfx[0] = arr[0];
        for (int i = 1; i < n ; i++){
            pfx[i] = pfx[i-1];
            if (arr[i] > 0){
                pfx[i] += arr[i];
            }
        }
        if (arr[n-1] < 0) sfx[n-1] = -arr[n-1];
        for (int i = n-2; i >= 0 ; i--){
            sfx[i] = sfx[i+1];
            if (arr[i] < 0){
                sfx[i] -= arr[i];
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++){
            ans = max(ans, pfx[i] + sfx[i]);
        }
        cout << ans << endl;
    }
}