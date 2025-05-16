#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
using namespace std;
#define endl '\n'
#define int long long

signed main() {_
    int s, t;
    cin >> s >> t;
    int matAdj[s][s];
    for (int i = 0; i < s; i++){
        for (int j = 0; j < s; j++){
            matAdj[i][j] = 0;
        }
    }

    for (int i = 0; i < t; i++){
        int a, b;
        cin >> a >> b;
        a--;b--;
        matAdj[a][b] = 1;
        matAdj[b][a] = 1;
    }

    int ans = 0;
    int q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        int a; cin >> a;
        a--;
        int p = 0;
        for (int i = 1; i < n; i++){
            int b;
            cin >> b;
            b--;
            if (matAdj[a][b] == 1) p++;
            a = b;
        }
        if (p == n-1) ans++;
    }
    cout << ans << endl;
}