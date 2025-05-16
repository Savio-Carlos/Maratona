#include <bits/stdc++.h>

using namespace std;

int main () {
   unsigned long long n, l, aux, res;

    cin >> l >> n;
    
    aux = (l - n) +1;

    res = pow(aux,2) + (l - aux);

    cout << res << "\n" << aux << "\n";

    return 0;
}
// 5-1 = 4 +1 = 5; 5pow2 = 25 + (5-0) = 25