#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
using namespace std;
#define endl '\n'
#define ll long long
const int MAXL = 1e6+7;

signed main() {_
    int tt; cin >> tt;
    while(tt--){
        int n; cin >> n;
        map<int,int> arr;
        int m = 0;
        for (int i = 0; i < n; i++){
            int a;
            cin >> a;
            arr[a]++;
            m = max(m,arr[a]);
        }
        int ans = n - m;
        ans += ceil(log2((double)n/m));
        cout << ans << endl;
    }  
}