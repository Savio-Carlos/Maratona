#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
using namespace std;
#define endl '\n'
#define int long long
const int MAXL = 1e5+7;

signed main() {_
    int t; cin >> t;
    while(t--){
        int l, r;
        cin >> l >> r;
        if (l == 1 && r == 1) cout << "1" << endl;
        else cout << r-l << endl;
    }   
}