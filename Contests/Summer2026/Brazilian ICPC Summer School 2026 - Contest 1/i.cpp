#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

signed main(){
    fastio;
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &u : a) cin >> u;

    int ans = 0;
    for (int i = 1; i < n; i++){
        if (a[i] < a[i-1]){
            ans += a[i-1] - a[i];
            a[i] = a[i-1];
        }
    }
    cout << ans << endl;
}