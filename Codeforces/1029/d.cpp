#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAX = 2e5+7;
const int INF = INT_MAX;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a) cin >> i;
    int cima = a[0]*n-a[n-1];
    int baixo = (n*n-1);
    if (cima < 0 || cima%baixo != 0) {
        cout << "NO" << endl;
        return;
    }
    int y = cima/baixo;
    int x = a[0] - n*y;

    if (x<0||x<0) {
        cout << "NO" << endl;
        return;
    }

    bool pos = true;
    for (int i = 1; i <= n; i++){
        if ((i*x + (n-i+1)*y)!=a[i-1])pos = false;
    }
    if (pos) cout << "YES" << endl;
    else cout << "NO" << endl;
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--) solve();
}