#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long
const int MAXL = 1e9+7;

signed main (){_
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        if ((n-1)%3 == 0 || n == 1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}