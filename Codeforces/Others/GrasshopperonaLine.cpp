#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
using namespace std;
#define endl '\n'
#define int long long
const int MAXL = 1e6+7;

signed main() {_
    int t; cin >>t;
    while(t--){
        int n, k;
        cin >> n >> k;
        if (n % k != 0) cout << "1" << endl << n << endl;
        else {
            int a,b;
            a = n-k-1;
            b = n-a;
            cout << "2" << endl << a << " " << b << endl;
        }
    }

}