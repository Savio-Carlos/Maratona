#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
using namespace std;
#define endl '\n'
#define int long long
const int MAXL = 1e5+7;

signed main() {_
    int t; cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<int> arr(n);
        for (auto &i:arr) cin >> i;
        cin >> m;
        bool possible = true;
        arr[0] = min(arr[0], m-arr[0]);
        for (int i = 1; i < n; i++){
            int temp = min(arr[i], m-arr[i]);
            int tmp = max(arr[i], m-arr[i]);
            if (temp >= arr[i-1]) arr[i] = temp;
            else if (tmp < arr[i-1]) possible = false;
            else arr[i] = tmp;
        }

       
        if (possible) cout << "YES" << endl;
        else cout << "NO" << endl;
    }   
}