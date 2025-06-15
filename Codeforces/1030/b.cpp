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
    if (n&1){
        cout << (n-2)*2+2 << endl;
        cout << 1 << " " << 2 << " " << n << endl;
        cout << 2 << " " << 1 << " " << n << endl;
        int l = 3, erre = 2;
        for (int i = 3; i <= n; i++){
            cout << i << " " << 1 << " " << erre << endl;
            cout << i << " " << l << " " << n << endl;
            l++;
            erre++;
        }
    }
    else {
        cout << (n-2)*2 + 1 << endl;
        cout << 1 << " " << 2 << " " << n << endl;
        cout << 2 << " " << 1 << " " << n << endl;
        int l = 3, erre = 2;
        for (int i = 3; i <= n-1; i++){
            cout << i << " " << 1 << " " << erre << endl;
            cout << i << " " << l << " " << n << endl;
            l++;
            erre++;
        }
        cout << n << " " << 1 << " " << n-1 << endl;
    }

}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--) solve();
}