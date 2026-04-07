#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int long long
#define ld long double
#define endl '\n'
#define winton ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)

signed main(){
    winton;
    int n;
    cin >> n;
    if (n%2 == 0 || (n >= 5 && (n-5)%2 == 0)) cout << "Y\n";
    else cout << "N\n";
}