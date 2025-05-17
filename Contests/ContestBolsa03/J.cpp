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
    int y;
    cin >> y;
    int ans;
    for (int i = 0; i < 4; i++){
        if ((y + i)%4 == 2) ans = y+i;
    }
    cout << ans << endl;
}