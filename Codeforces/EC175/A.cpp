#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long
const int MAXL = 1e9+7;

signed main() {_
    int t; cin >> t;
    while(t--){
        int n;
        cin >> n;
        int ans = n/15;
        int temp = ans*15;
        ans*=3;
        for (int i = temp; i <= n; i++){
            if (i%15 <=2) ans++;
        }
        cout << ans << endl;
    }
}

/*
 for(int i = 0; i <= n; i+=15) ans++;
        for(int i = 1; i <= n; i+=15) ans++;
        for(int i = 2; i <= n; i+=15) ans++;
         cout << ans << endl;
*/