#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
using namespace std;
#define endl '\n'
#define int long long
const int MAXL = LLONG_MAX;

signed main(){_
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> arr(n+1);
        for (int i = 1; i <= n; i++){
            cin >> arr[i];
        }
        arr[0] = arr[n];
        if (arr[0] == arr[1]) cout << "NO" << endl;
        else {
            cout << "YES" << endl;
            for (int i = 0; i < n; i++) cout << arr[i] << " ";
            cout << endl;

        }
    }
}