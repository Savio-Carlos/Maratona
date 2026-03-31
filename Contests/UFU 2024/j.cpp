#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int long long
#define ld long double
#define endl '\n'

#define winton ios_base::sync_with_stdio(false),cin.tie(0)

signed main(){
    winton;
    int n;
    cin >> n;
    if (n < 3) {
        cout << 0 << endl;
        return 0;
    }
    int m2 = (n-1)/4;
    int m0 = (n+1)/4;
    cout << (m2*(m2+1)/2) + (m0*(m0+1)/2) << endl; 
}