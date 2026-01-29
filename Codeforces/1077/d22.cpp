#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        ll x, y;
        cin >> x >> y;
        
        ll best_cost = LLONG_MAX;
        ll best_p = 0, best_q = 0;
        
        auto update = [&](ll p, ll q) {
            if ((p & q) != 0) return;
            ll cost = abs(x - p) + abs(y - q);
            if (cost < best_cost) {
                best_cost = cost;
                best_p = p;
                best_q = q;
            }
        };
        
        ll common = x & y;
        
        // Option 1: p = x, q = y without common bits
        update(x, y ^ common);
        
        // Option 2: p = x without common bits, q = y
        update(x ^ common, y);
        
        // Option 3: one of them is 0
        update(0, y);
        update(x, 0);
        
        // Option 4: try powers of 2 and (power of 2 - 1)
        for (int k = 0; k <= 31; k++) {
            ll pow2 = 1LL << k;
            ll pow2m1 = pow2 - 1;
            
            // p = 2^k, find best q
            {
                ll q;
                if ((y & pow2) == 0) {
                    q = y; // no conflict at bit k
                } else {
                    // y has bit k, need to remove it
                    ll opt1 = y ^ pow2;  // just remove bit k
                    ll opt2 = pow2m1;    // round down to 2^k - 1
                    q = (abs(y - opt1) <= abs(y - opt2)) ? opt1 : opt2;
                }
                update(pow2, q);
            }
            
            // q = 2^k, find best p
            {
                ll p;
                if ((x & pow2) == 0) {
                    p = x;
                } else {
                    ll opt1 = x ^ pow2;
                    ll opt2 = pow2m1;
                    p = (abs(x - opt1) <= abs(x - opt2)) ? opt1 : opt2;
                }
                update(p, pow2);
            }
            
            // p = 2^k - 1, q has no bits below k
            {
                ll p = pow2m1;
                ll q = y & ~pow2m1;
                update(p, q);
            }
            
            // q = 2^k - 1, p has no bits below k
            {
                ll q = pow2m1;
                ll p = x & ~pow2m1;
                update(p, q);
            }
        }
        
        cout << best_p << " " << best_q << "\n";
    }
    return 0;
}
