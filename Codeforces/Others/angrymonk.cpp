#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int t;
    ll n, k;
    cin >> t;
    while (t--){
        ll ans = 0, maior = 0, l;
        cin >> n >> k;
        for (int i = 0; i < k; i++){
            cin >> l;
            ans += (l+l-1);
            maior = max(maior, l);
        }
        ans -= maior+maior-1;
        cout << ans << endl;
    }
}