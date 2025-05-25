#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAX = 2e5+7;
const int INF = INT_MAX;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

signed main(){
    int y, k;
    cin >> y >> k;
    int b = 1;
    while (k--){
        b += gcd(b,y);
        cout << "current X: " << b << " gcd: " << gcd(b,y) << " k restantes: " << k << endl; 
    }
    b += (k+1)*y;
    cout << b << endl;
}