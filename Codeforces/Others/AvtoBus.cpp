#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
using namespace std;
#define endl '\n'
#define int long long
const int MAXL = 1e6+7;

signed main() {_
    int t; cin >> t;
    while (t--){
        int n;
        cin >> n;
        if (n%2 != 0 || n < 4){
            cout << "-1" << endl;
            continue;
        }
        int maior, menor;
        maior = n/4;
        menor = n/6;
        if (n%6 != 0) menor++;
        cout << menor << " " << maior << endl;
    }
}