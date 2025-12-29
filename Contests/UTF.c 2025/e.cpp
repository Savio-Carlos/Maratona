#include <bits/stdc++.h>
#include <random>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
// #define endl '\n'
#define int long long
#define ld long double

signed main(){
    int p;
    cin >> p;
    int fator = max(1LL,p/8);
    for (int i = 1; i <= 8; i++){
        int a = fator*i;
        if (a < 2 || a > p-1) continue;
        cout << "? " << a << " " << 2 << endl;
        int ans;
        cin >> ans;
        if (ans == -1){
            cout << ":(\n";
            return 0;
        }
    }
    cout << ":)\n";
}