#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
using namespace std;
#define endl '\n'
#define int long long

signed main() {_
    int n;
    cin >> n;
    vector<pair<string,string>> names(n);

    for (int i = 0; i < n; i++){
        cin >> names[i].second;
        cin >> names[i].first;
    }
    sort(names.begin(), names.end());
    for (int i = 0; i < n; i++){
        cout << names[i].second << " " << names[i].first << endl;
    }
}