#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, b, v;
    cin >> n >> b >> v;
    if (((b-v)%n) == 0) cout << ((b-v)/n) << endl;
    else cout << -1 << endl; 
}