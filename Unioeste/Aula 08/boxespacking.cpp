#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
using namespace std;
#define endl '\n'
#define int long long
const int MAXL = 1e6+7;

signed main() {_
    int n; cin >> n;
    vector<int> caixas;
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        caixas.push_back(a);
    }
    sort(caixas.begin(), caixas.end());
    int ans = 1, temp = 1;
    for (int i = 0; i < n; i++){
        if (caixas[i] == caixas[i+1]){
            temp++;
        }
        else temp = 1;
        ans = max(ans, temp);
    }
    cout << ans << endl;
}