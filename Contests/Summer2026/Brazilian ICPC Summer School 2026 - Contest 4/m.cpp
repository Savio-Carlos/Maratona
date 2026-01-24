#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(1); cin.tie(0)
#define ll long long
#define dbg(x) cout << x << " "; 
#define endl '\n'

void solve(){
    double pi = acos(-1.0);
    double d, l; 
    cin >> d >> l;
    double h =  sqrt(((l/2.0) * (l/2.0)) - (((d/2) * (d/2))));
    cout << pi * h * (l/2) << endl;
}

signed main(){
    fastio;
    int t; cin >> t;
    while(t--) solve();
}