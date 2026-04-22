#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long
const int MAXL = 1e5+7;

signed main() {_
    int t; cin >> t;
    while (t--){
        int n, sum = 0; 
        cin >> n;
        for (int i = 0; i < n; i++){
            int a; cin >> a;
            sum += a;
        }
        if (sum%2 == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}