#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
using namespace std;
#define endl '\n'
#define int long long
const int MAXL = 1e5+7;

signed main() {_
    int t; cin >> t;
    while(t--){
        string s;
        cin >> s;
        bool possible = false;
        for (int i = 1; i < s.size(); i++){
            if (s[i] == s[i-1]) possible = true;
        }
       if (possible) cout << "1" << endl;
       else cout << s.size() << endl;
    }   
}