#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long
const int MAXL = 1e5+7;
signed main() {_
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0, mx = 0, smx = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
        if (a[i] >= mx){
            smx = mx;
            mx = a[i];
        }
        else smx = max(smx, a[i]);
    }

    vector<int> ans;
    for (int i = 0; i < n; i++){
        if (a[i] == mx){
            if ((sum - a[i] - smx) == smx) ans.push_back(i+1);
        }
        else if (sum - a[i] - mx == mx) ans.push_back(i+1);
    }
    cout << ans.size() << endl;
    for (auto u : ans) cout << u << " ";
}