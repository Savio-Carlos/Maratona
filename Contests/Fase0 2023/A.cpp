#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAXN = 2e5+7;

signed main(){
    winton;
    ld n, k;
    cin >> n >> k;
    ld r = round(sqrt(k));
    int x = (2*n+1) - r;
    int y = 2*n * 2*n;
    y /= (x*x);
    cout << (y*x) * y * x << endl;
}