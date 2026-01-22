#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define int long long
#define ld long double
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)

void solve(){
    int n;
    cin >> n;
    if (n%3) cout << "First\n";
    else cout << "Second\n";
}

signed main(){
    winton;
    int t;
    cin >> t;
    while (t--) solve();
}