#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
using namespace std;
#define endl '\n'
#define int long long
const int MAXL = 1e6+7;

signed main() {_
    int a, m;
    cin >> a >> m;
    for (int i = 0; i < m; i++){
        if (a%m == 0){
            cout << a << " " << m << endl;
            cout << "Yes" << endl;
            return 0;
        } 
        a += a%m;
    }
    cout << "No" << endl;
}
