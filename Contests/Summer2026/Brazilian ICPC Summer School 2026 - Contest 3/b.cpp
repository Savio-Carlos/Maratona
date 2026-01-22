#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define int long long
#define ld long double
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)

void solve(int t){
    int n;
    cin >> n;
    vector<int> w(n), b(n);
    for (auto &u : w) cin >> u;
    for (auto &u : b) cin >> u;
    int xsum = 0;
    for (int i = 0; i < n; i++) xsum ^= ((b[i] - w[i]) - 1);
    cout << "Case " << t << ": ";
    if (xsum) cout << "white wins" << endl;
    else cout << "black wins" << endl;
    
}

signed main() {    
    winton;
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) solve(i);
}