#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int t, cnt;
    ll l, r, aux;
    cin >> t;
    while (t--){
        cin >> l >> r;
        aux = 1;
        cnt = 1;
        while (l <= r){
            l+=aux;
            aux++;
            cnt++;
        }
        cout << cnt-1 << endl;
    }
}