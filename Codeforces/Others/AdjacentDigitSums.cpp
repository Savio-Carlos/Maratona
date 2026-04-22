#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
using namespace std;
#define endl '\n'
#define int long long
const int MAXL = 1e6+7;

signed main() {_
    int t;
    cin >> t;
    while(t--){
        int x, y;
        cin >> x >> y;
        if (((x+1-y)%9) == 0 && (x+1-y) > 0) cout << "Yes" << endl;
        else if (y - x == 1) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}