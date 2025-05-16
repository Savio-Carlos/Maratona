#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9+7;

ll ans[100001][5];

int main (){
    int n; cin >> n;
    ans [0][2] = -INF;
    ans [0][3] = INF;
    ans [0][4] = 0;
    for (int i = 1; i <= n; i++){    
        int op;
        cin >> op;
        if (op == 1){
            ll x; cin >> x;
            ans [i][2] = max(ans[i-1][2], x);
            ans [i][3] = min(ans[i-1][3], x);
            ans [i][4] = ans[i-1][4] + x;
        }
        else {
            int p; cin >> p;
            ans [i][2] = ans[i-1][2];
            ans [i][3] = ans[i-1][3];
            ans [i][4] = ans[i-1][4];

            cout << ans[p][op] << endl;
        }
    }  
}