#include <bits/stdc++.h>
using namespace std;

int main(){
    double r, c;
    cin >> r >> c;
    c = r - c;
    cout << fixed << setprecision(8) << ((c*c) / (r*r)) * 100 << endl;
}