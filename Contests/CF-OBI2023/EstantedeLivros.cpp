#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)

signed main () {
    winton;
    int x, y, z, n;
    cin >> x >> y >> z >> n;
    int total = x+y+z;
    int ans = total%n;
    cout << ans << endl;
}