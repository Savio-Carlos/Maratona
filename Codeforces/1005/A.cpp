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
        int n; cin >> n;
        string s; cin >> s;
            
        int ans = 0, temp = 0;
        for (int i = n-2; i >= 0; i--){
            if (s[i] == '1' && s[i+1] != '1') ans+=2;
        }
        if (s[n-1] == '1') ans++;
        cout << ans << endl;
    }
}