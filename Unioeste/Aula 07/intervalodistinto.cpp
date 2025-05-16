#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
using namespace std;
#define endl '\n'
#define int long long
const int MAXL = 1e5+7; 

signed main() {_
    int n;
    cin >> n;
    vector<int> p(MAXL, 0);
    int ans = 0, cur = 0;
    int inicio = 0;
    for (int i = 1; i <= n; i++){
        int a;
        cin >> a;
        if (p[a]){
            if (p[a] > inicio){
                inicio = p[a];
            }
        }
        cur = i-inicio;
        p[a] = i;
        ans = max(cur,ans);
        //cout << ans << " " << inicio << endl;
    }
    
    cout << ans << endl;
}