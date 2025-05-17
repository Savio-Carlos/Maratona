#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAX = 34;

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n), l(n), r(n);
        for (auto &u : a) cin >> u;
        int ls = 0, rs = 0;
        for (int i = 0; i < n-1; i++){
            if (a[i] < a[i+1]) ls++;
            else if (a[i] > a[i+1]) rs++;
        }
        // cout << ls << endl;
        // cout << rs << endl;
        l[0] = ls;
        r[n-1] = rs;
        for (int i = 1; i < n; i++){
            if (a[i] > a[i-1]) ls--;
            l[i] = ls;
        }
        for (int i = n-2; i >= 0; i--){
            if (a[i] > a[i+1]) rs--;
            r[i] = rs;
        }
        // for (auto u : l) cout << u <<" ";cout<<endl;
        // for (auto u : r) cout << u <<" ";cout<<endl;
        for (int i = 0; i < n; i++){
            cout << max(l[i],r[i]) << " ";
        }
        cout << endl;
    }
}