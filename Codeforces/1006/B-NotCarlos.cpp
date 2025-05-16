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
        string s;
        cin >> n >> s;
        int underl = 0, overl = 0;
        for (auto &i : s){
            if (i=='-') overl++;
            else underl++;
        }
        int a = overl/2 + overl%2;
        int b = overl/2;
        if (n >=3 )cout << a * underl * b << endl;
        else cout << '0' << endl;
    }
}