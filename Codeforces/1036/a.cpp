#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
const int MAX = 2e5+7;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f3f3f3f3fLL;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &u : a) cin >> u;
    vector<int> sorted = a;
    sort(all(sorted));
    if (a == sorted){
        cout << "No\n";
        return;
    }

    cout << "Yes\n" << 2 << endl;
    for (int i = 1; i < n; i++){
        if (a[i] < a[i-1]){
            cout << a[i-1] << " " << a[i] << endl;
            return;
        }
    }
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--)solve();
}
