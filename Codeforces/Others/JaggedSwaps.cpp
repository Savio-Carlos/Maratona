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
        vector<int> per(n);
        for (auto &i : per) cin >> i;

        if (per[0] == 1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }   
}