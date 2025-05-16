#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int t;
    cin >> t;
    while(t--){
        int n, m, ans = 0, tam = 0;
        cin >> n >> m;
        vector<string> s(n);
        for (int i = 0; i < n; i++){
            cin >> s[i];
        }
        for (int i = 0; i < n; i++){
            int l = s[i].length();
            if (tam+l > m) break;
            ans++;
            tam+=l;
        }
        cout << ans << endl;
    }
}