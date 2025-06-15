#include <bits/stdc++.h>
using namespace std;


int main(){
    int n, m;
    cin >> n >> m;
    int tot = 0;
    for (int i = 0; i < n; i++){
        int p, g, c;
        cin >> p >> g >> c;
        tot += (p*4 + g*9 + c*4);
    }
    cout << m - tot << endl;
}