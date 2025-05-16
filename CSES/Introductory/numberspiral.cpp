#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
using namespace std;
#define endl '\n'
#define int long long

signed main() {_
    int t;
    cin>>t;
    while(t--){
        int a, b;
        cin >> a >> b;
        int r = max(a,b);
        int m = min(a,b);
        cout << (r*r) - (m-1) << endl;
    }

}