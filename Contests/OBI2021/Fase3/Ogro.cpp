#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAXN = 1e6+7;
const int LOG = 20;
const int INF = INT_MAX;

signed main () {
    winton;
    int n;
    cin >> n;
    if (n == 0) {
        cout << "*" << endl << "*" << endl;
    }
    else if (n <= 5){
        for (int i = 1; i <= n; i++){
            cout << "I";
        }
        cout << endl << "*" << endl;
    }
    else {
        n -= 5;
        for (int i = 1; i <= 5;  i++){
            cout << "I";
        }
        cout << endl;
        for (int i = 1; i <= n; i++){
            cout << "I";
        }
        cout << endl;
    }

}