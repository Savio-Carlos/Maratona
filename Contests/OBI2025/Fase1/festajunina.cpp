#include <bits/stdc++.h>
using namespace std;

int main(){
    int e, s, m;
    cin >>e >>s >> m;
    cout << abs(e-s) + abs(e-m) + abs(s-m) << endl;

    vector<int> a(3);
    a[0] = 10;
    a[1] = 5;
    a[2] = 13;
    sort(a.begin(), a.end());
    for (auto u : a) cout << u << " ";
}