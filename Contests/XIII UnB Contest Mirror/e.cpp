#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

const int MAX = 1e2+7;

vector<int> teg[MAX];

signed main(){
    fastio;
    int q;
    cin >> q;
    int s = 1;
    while(q--){
        int t;
        cin >> t;
        if (t == 1){
            teg[s++].push_back(0);
        }
        else if (t == 2){
            int i, x;
            cin >> i >> x;
            teg[i].push_back(x);
        }
        else {
            int i, j;
            cin >> i >> j;
            cout << teg[i][j] << endl;
        }
    }
}