#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
using namespace std;
#define endl '\n'
#define int long long
#define all(x) (x).begin(), (x).end()
const int MAXL = 1e5+7;

signed main() {_
    int n; cin >> n;
    set<int> numbres;
    for (int i = 0; i < n; i++){
        int a; cin >> a;
        numbres.insert(a);
    }
    cout << numbres.size()<<endl;
}