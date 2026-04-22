#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
using namespace std;
#define endl '\n'
#define int long long
const int MAXL = 1e6+7;

signed main() {_
    int t; cin >> t;
    while(t--){
        int ans = LLONG_MAX;
        int n, k; cin >> n >> k;
        int npares = 0;
        for (int i = 0; i < n; i++){
            int a; cin >> a;
            if (k == 4) {
                if (a%2 == 0) npares++;
                if (a%k){
                    ans = min(ans, k-(a%k));
                }
                else ans = 0;
            }
            else {
                if (a <= k){
                    ans = min (ans, k-a);
                }
                else if (a%k == 0) ans = 0;
                else {
                    ans = min(ans, k-(a%k));
                }
            }
           
        }
        if (k == 4 && npares >= 2) ans = 0;
        else if (k == 4) ans = min(ans, 2-npares);
        cout << ans << endl;
    }
}