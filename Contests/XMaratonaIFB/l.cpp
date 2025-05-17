#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAX = 2e5+7;

signed main(){
    winton;
    int n, x;
    cin >> n >> x;
    vector<int> acidez(n), quality(n);
    for (int i = 0; i < n; i++){
        int a, q;
        cin >> a >> q;
        acidez[i] = a;
        quality[i] = q;
    }
    vector<int> ans(n+1);
    for (int i = 0; i < (1<<n); i++){
        int cura = 0, curq = 0;
        int idx = __builtin_popcount(i);
        for (int j = 0; j < n; j++){
            int pos = (1<<j);
            if (i & pos){
                cura+=acidez[j];
                curq+=quality[j];
            }
        }
        if (cura <= x)ans[idx] = max(ans[idx], curq);
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
}