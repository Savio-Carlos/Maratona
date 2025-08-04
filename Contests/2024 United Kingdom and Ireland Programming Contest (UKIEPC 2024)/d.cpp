#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    cout << fixed << setprecision(9);

    while(q--){
        double p, r, y;
        cin >> p >> r >> y;

        // C = n + e
        double C = (p + r + y) * 0.5;

        // Binary search T
        double lo = 0, hi = fabs(C) + fabs(p) + fabs(r) + 5;
        for(int it = 0; it < 80; it++){
            double T = 0.5*(lo + hi);
            // build intervals for n and e
            double n_lo = max(-T, r - T);
            double n_hi = min( T, r + T);
            double e_lo = max(-T, p - T);
            double e_hi = min( T, p + T);
            // from n+e=C => n in [C-e_hi, C-e_lo]
            double req_lo = C - e_hi;
            double req_hi = C - e_lo;
            // intersect with n-range
            if(max(n_lo, req_lo) <= min(n_hi, req_hi))
                hi = T;
            else
                lo = T;
        }

        double T = hi;
        // final intervals
        double n_lo = max(-T, r - T);
        double n_hi = min( T, r + T);
        double e_lo = max(-T, p - T);
        double e_hi = min( T, p + T);
        double req_lo = C - e_hi;
        double req_hi = C - e_lo;
        // pick n = leftmost feasible
        double n = max(n_lo, req_lo);
        double e = C - n;
        double s = n - r;
        double w = e - p;

        cout << n << " "
             << e << " "
             << s << " "
             << w << "\n";
    }
    return 0;
}
