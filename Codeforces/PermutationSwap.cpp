#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
using namespace std;
#define endl '\n'
#define ll long long
const int MAXL = 1e6+7;

signed main() {_
    int t; cin >> t;
    while(t--){
        int n;
        cin >> n;
        int ans = 0;
        for (int i = 1; i <= n; i++){
            int a; cin >> a;
            if (a == i) continue;
            ans = gcd(ans, abs(a-i)); 
        }
        cout << ans << endl;
    }  
}