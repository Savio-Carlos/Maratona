#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAX = 5e4+7;

signed main(){
    winton;
    int w, a, b, c;
    cin >> w >> a >> b >> c;
    if (w - (a+b+c) >= 0) cout << "S" << endl;
    else cout << "N" << endl;  
}