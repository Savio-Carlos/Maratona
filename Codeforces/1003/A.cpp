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
        for (int i = 0; i < s.size()-2; i++){
            cout << s[i];
        }
        cout << 'i' << endl;
    }
}