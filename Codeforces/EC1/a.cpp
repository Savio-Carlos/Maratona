#include <bits/stdc++.h>
using namespace std;

#define int long long
#define winton ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

void solve(){
    int n;
    cin >> n;
    int p = log2(n) + 1;
    cout << ((n * (n+1)) / 2) - (2 * ((1 << p) - 1)) << endl;
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--) solve();
}