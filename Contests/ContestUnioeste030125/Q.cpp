#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
using namespace std;
#define endl '\n'
#define int long long
const int MAX = 10e9+7;

signed main() {_
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int r = n-1;
    int ans = MAX;
    for (int i = 0; i < n/2; i++, r--){
        int cur = arr[i]+arr[r];
        ans = min(ans,cur); 
    }
    cout << ans << endl;
}