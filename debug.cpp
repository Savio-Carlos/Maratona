#include <bits/stdc++.h>
using namespace std;
#define int long long
int mn[18], mx[18];
int fastExpo(int base, int exp) {
    int res = 1;
    while(exp) {
        if (exp & 1) res = res * base;
        base = base * base;
        exp >>= 1;
    }
    return res;
}
void calc(){
    mn[1] = 1;
    mx[1] = 3;
    for (int i = 2; i < 18; i++){
        int maior = fastExpo(10LL, i) - 1;
        int maior_sq = sqrt(maior);
        mn[i] = mx[i-1] + 1;
        mx[i] = (maior_sq * maior_sq == maior) ? maior_sq + 1 : maior_sq;
    }
}
int32_t main() {
    calc();
    for(int i=1; i<=17; i++) cout << i << ": mn=" << mn[i] << " mx=" << mx[i] << endl;
    return 0;
}
