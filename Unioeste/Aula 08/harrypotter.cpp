#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
using namespace std;
#define endl '\n'
#define int long long
const int MAXL = 1e6+7;

signed main() {_
    set<string> ans;
    int n;
    cin >> n;
    while(n--){
        string a;
        cin >> a;
        if (ans.find(a) != ans.end()){
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
            ans.insert(a);
        }
    }
}