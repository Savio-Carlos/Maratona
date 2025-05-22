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
    int t;
    cin >> t;
    while (t--){
        int x, y;
        cin >> x >> y;
        bool ans = false;
        if ((x >= 0 && x <= 200 && y <= 0 && y >= -100) || (x <= 0 && x >= -200 && y >= 0 && y <= 100)){
            if (abs(x) + abs(y) <= 200) ans = true;
        }
        else if ((x >= 0 && x <= 100 && y >= 0 && y <= 100) || (x <= 0 && x >= -100 && y <= 0 && y >= -100)){
            if (abs (x) + abs(y) <= 100) ans = true;
        }
        if (ans) cout << "S" << endl;
        else cout << "N" << endl;
    }
}