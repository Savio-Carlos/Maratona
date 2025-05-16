#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
using namespace std;
#define endl '\n'
#define ll long long
const int MAXL = 1e6+7;

signed main(){_
    int n;
    cin >> n;
    vector<vector<int>> matAdj(n,vector<int>(n));

    for(int i = 0; i < n; i++){
        int ix; cin >> ix;
        int q; cin>>q;
        for (int j = 0; j < q; j++){
            int a;
            cin >> a;
            matAdj[ix-1][a-1] = 1;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (j > 0) cout << ' ';
            cout << matAdj[i][j];
        }
        cout << endl;
    }
}