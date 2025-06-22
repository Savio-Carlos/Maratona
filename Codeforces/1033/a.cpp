#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define debug(x) cout << #x << " = " << x << "\n";
const int MAX = 5e5+7;
const int INF = LLONG_MAX;

void solve(){
    int l1, b1, l2, b2, l3, b3;
    cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;
    if (l2 + l3 == l1 && b1 + b2 == b1 + b3 && l1 == b1+b2)  cout << "YES" << endl;
    else if (b2 + b3 == b1 && l1 + l2 == l1 + l3 && b1 == l1+l2)cout << "YES" << endl;
    else if (b1+b2+b3 == l1 && b1+b2+b3 == l2 && b1+b2+b3 == l3) cout << "YES" << endl;
    else if (l1+l2+l3 == b1 && l1+l2+l3 == b2 && l1+l2+l3 == b3) cout << "YES" << endl;
    else cout << "NO" << endl;
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--) solve();
}