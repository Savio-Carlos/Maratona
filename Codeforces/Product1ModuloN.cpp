#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
using namespace std;
#define endl '\n'
#define int long long
const int MAXL = 1e9+7;

signed main() {_
    int n; cin >> n;
    vector<int> prod;
    int product = 1;
    for (int i = 1; i < n; i++){
        if (gcd(i,n) == 1){
            product = (product * i) % n;
            prod.push_back(i);
        }
    }

    if (product%n != 1){
        prod.pop_back();
    }

    cout << prod.size() << endl; 
    for (int i : prod) cout << i << " ";
    cout << endl; 
}

