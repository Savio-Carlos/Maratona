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
        vector<int> a(n), b(n);
        for (auto &u : a)cin >> u;
        for (auto &u : b)cin >> u;
        int pardiff = 0, impardiff = 0;
        int nimpar = 0, npar = 0;
        for (int i = 0; i < n; i++){
            if (a[i]%2) nimpar++;
            else npar++;
            if (a[i] == b[i]) continue;
            int diff = abs(a[i]-b[i])%2;
            if (diff) impardiff++;
            else pardiff++;
        }
        if (impardiff == 0 && pardiff == 0){
            cout << "YES" << endl;
            continue;
        }
        else if (impardiff > 1){cout<<"NO"<<endl;continue;}
        else if (impardiff == 1){
            if (nimpar%2 == 1) cout << "YES" << endl;
            else cout << "NO" << endl;
            continue;
        }
        else if (npar%2==0){
            cout << "YES" << endl;
            continue;
        }
        else {
            cout << "NO" << endl;
            continue;
        }
    }
}