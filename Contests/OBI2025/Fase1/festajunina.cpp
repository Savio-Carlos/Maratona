#include <bits/stdc++.h>
using namespace std;

int main(){
    int e, s, m;
    cin >>e >>s >> m;
    cout << abs(e-s) + abs(e-m) + abs(s-m) << endl;

}