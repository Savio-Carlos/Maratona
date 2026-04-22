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
        for (auto &i : arr) cin >> i;
    
        int ans = 0, temp = 0;
        for (int i = 0; i < n; i++){
            if (arr[i] == 0){
                temp++;
            }
            else temp = 0;
            ans = max(ans, temp);
        }
        cout << ans << endl;
    }
}