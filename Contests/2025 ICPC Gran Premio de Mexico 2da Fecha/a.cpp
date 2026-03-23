#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fastio ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)



signed main(){
    fastio;
    int l, r, val;
    cin >> l >> r >> val;
    cout << r / val - (l-1) / val << endl;
}