#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
using namespace std;
#define endl '\n'
#define int long long
const int MAXL = 1e5+7;

signed main() {_
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n+1);
        int ans = 0;
        map<int, int> diff;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            diff[i-a[i]]++;
            if (diff[i-a[i]] > 1){
                ans += diff[i-a[i]] -1;
            }
        }
        cout << ans << endl;
    }   
}w