#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio ios_base::sync_with_stdio(0),cin.tie(0)

int main(){
    int a, x;
    cin >> a >> x;
    if (gcd(a,x) != 1){
        cout << -1 << endl;
        return 0;
    }
    for (int y = 1; y <= 100000; y++){
        if ((x*y) % a == 1 and x*y > a){
            cout << y << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}