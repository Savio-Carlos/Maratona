#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAX = 2e5+7;
const int LOG = 20;

int n, q, sp[MAX][LOG+1], arr[MAX];

void compute(){
    for (int j = 1; j <= LOG; j++){
        for (int i = 0; i +(1<<(j-1)) <= n ; i++){
            sp[i][j] = sp[i][j-1] + sp[i+(1<<(j-1))][j-1];
        }
    }
}

int query(int a, int b){
    int ans = 0;
    for (int j = LOG; j >= 0; j--){
        if (a + (1<<j) - 1 <= b){
            ans += sp[a][j];
            a+=(1<<j);
        }
    }
    return ans;
}

signed main() {
    winton;
    cin >> n >> q;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        sp[i][0] = arr[i];
    }
    compute();
    while (q--){
        int a, b;
        cin >> a >> b;
        cout << query(a-1,b-1) << endl;
    }
}
