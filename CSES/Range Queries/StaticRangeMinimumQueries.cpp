#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAX = 2e5+7;
const int LOG = 20;

int n, q, arr[MAX], sp[MAX][LOG];

void build(){
    for (int j = 1; j < LOG; j++){
        for (int i = 0; i < n-(1<<j)+1; i++){
            sp[i][j] = min(sp[i][j-1], sp[i+(1<<(j-1))][j-1]);
        }
    }
}

int query(int l, int r){
    int len = r-l+1;
    int lg = 31 - __builtin_clz(len);
    //cout << "log: " << lg << " " << sp[l][lg] << " " << sp[r-(1<<lg)+1][lg] << endl;
    return min(sp[l][lg], sp[r-(1<<lg)+1][lg]);
}

signed main() {
    winton;
    cin >> n >> q;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        sp[i][0] = arr[i];
    }
    build();

    while(q--){
        int a, b;
        cin >> a >> b;
        a--; b--;
        cout << query(a,b) << endl;
    }
}