#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define int long long
#define ld long double
#define winton ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

signed main(){
    winton;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a == 1){
        int ans = ((d - c) + b) / b;
        cout << ans << endl;
        return 0;
    }
    int cur = c;
    int dia = 0;
    while(cur <= d){
        dia++;
        cur = cur*a + b;
    }
    cout << dia << endl;
}