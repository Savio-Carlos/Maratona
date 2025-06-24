#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        long long n, m;
        cin >> n >> m;

        long long total_max = n * (n + 1) / 2;
        if (m < n || m > total_max) {
            cout << "-1\n";
            continue;
        }

        if (m == n) {
            cout << "1\n";
            for (long long i = 2; i <= n; i++) {
                cout << "1 " << i << '\n';
            }
            continue;
        }

        long long k0 = min(n, m - n + 1);

    for (long long k = k0; k >= 2; k--) {
        long long resto = m - (k + n - 1);
        if (resto < 0) {
            continue;
        }
        long long S = (k - 2) * (k - 1) / 2;
        long long xismin = 0;
        if (resto > S) {
            xismin = (resto - S + k - 2) / (k - 1);
        }
        long long xismax = min(n - k, resto / (k - 1));

    
        if (xismin <= xismax) {
            long long x_use = xismin;
            long long T_prime = resto - x_use * (k - 1);
            cout << k << '\n';
            cout << k << " " << 1 << '\n';

            vector<bool> attached(n + 1, false);
            attached[1] = true;
            attached[k] = true; // Node k is now part of the tree.

            // Greedily construct T_prime by connecting nodes {2, ..., k-1} to k.
            for (long long upgrade = k - 2; upgrade >= 1; upgrade--) {
                if (T_prime >= upgrade) {
                    long long node_to_attach = upgrade + 1;
                    cout << k << " " << node_to_attach << '\n';
                    attached[node_to_attach] = true;
                    T_prime -= upgrade;
                }
            }

            // Connect x_use nodes {k+1, ...} to k.
            for (long long i = 1; i <= x_use; i++) {
                long long node_to_attach = k + i;
                if (node_to_attach > n) break;
                cout << k << " " << node_to_attach << '\n';
                attached[node_to_attach] = true;
            }

            // Connect any remaining unattached nodes to node 1.
            for (long long j = 2; j <= n; j++) {
                if (!attached[j]) {
                    cout << 1 << " " << j << '\n';
                }
            }
            return 0; // Solution found and printed, exit the function.
        }
    }
}
    // If the loop completes without returning, no solution was found.
    cout << "-1\n";
    return 0;
}