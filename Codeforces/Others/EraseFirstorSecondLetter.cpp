#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
using namespace std;
#define endl '\n'
#define int long long
const int MAXL = 1e9+7;

signed main() {_
    int t; cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n >> s;
        vector<int> occ(26,n), ans(n,0);

        ans[n - 1] = 1;  // ultimo char e uma possivel string
        occ[s[n - 1] - 'a'] = n - 1;  // marca a posicao do ultimo caracter

        for (int i = n-2; i >= 0; i--){
            ans[i] = ans[i+1] + (occ[s[i]-'a'] - i);
            occ[s[i]-'a'] = i; 
            cout << "ans[i]: " << ans[i] << endl;
            cout << "i: " << i << endl;
            cout << "occ[s[i]]-'a': " << occ[s[i]-'a'] << endl;
            cout << "s[i]: " << s[i] << endl << endl;

        }
        cout << ans[0] << endl;
    }
}