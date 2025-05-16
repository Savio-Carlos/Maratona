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
        vector<int> brr(n-2);
        bool arr = true;
        for (int i = 0; i < n-2; i++){
            cin >> brr[i];
        }
        for (int i = 1; i < n-3; i++){
            if (brr[i-1] == 1 && brr[i] == 0 && brr[i+1] == 1) {
                arr = false;
            }
        }
        if (arr) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}