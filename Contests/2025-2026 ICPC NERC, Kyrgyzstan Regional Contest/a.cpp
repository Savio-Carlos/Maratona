#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0),cin.tie(0);

signed main(){
    fastio;
    int x1, x2, x3, x4, x5, x6;
    cin >> x1 >> x2 >> x3 >> x4 >> x5 >> x6;
    cout << (x1*x3*x5) + (x1*x3*x6) + (x1*x4*x5) + (x1*x4*x6) + (x2*x3*x5) + (x2*x3*x6) + (x2*x4*x5) + (x2*x4*x6) << endl; 
}