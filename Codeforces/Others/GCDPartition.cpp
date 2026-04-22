#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
using namespace std;
#define endl '\n'
#define int long long
const int MAXL = 1e6+7;

signed main() {_
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> arr(n);
        int sum2 = 0;
        for (auto &u : arr){
            cin >> u;
            sum2 += u;
        }
        int ans = 0, sum1 = 0, gcdd = 0;
        for (int i = 0; i < n-1; i++){
            sum1 += arr[i];
            sum2 -= arr[i];
            gcdd = gcd(sum1,sum2);
            ans = max(ans,gcdd);
            //cout << "soma 1 : " << sum1 << endl;
            //cout << "soma 2 : " << sum2 << endl;
            //cout << "gcd : " << gcdd << endl;
            //cout << "ans : " << ans << endl << endl;
        }
        cout << ans << endl;
    }
}