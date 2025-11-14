#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// Global variables to store state
int n;
vector<int> b;          // Stores the input products
vector<int> a;          // Stores the array we are building
vector<bool> used;      // Tracks which elements of 'b' have been used
bool found = false;     // Flag to stop search once solution is found

void solve(int idx) {
    // If we found a solution, stop all other recursive branches
    if (found) return;

    // Base case: If we have filled the array A up to index n, we are done
    if (idx == n) {
        found = true;
        cout << "Yes" << endl;
        for (int i = 0; i < n; ++i) {
            cout << a[i] << (i == n - 1 ? "" : " ");
        }
        cout << endl;
        return;
    }

    // The current previous element is a[idx-1]
    int prev = a[idx - 1];

    // Try to find a matching product in b
    for (int i = 0; i < n - 1; ++i) {
        // Skip used products
        if (used[i]) continue;

        // Optimization: Duplicate Handling
        // If this value is the same as the previous one and the previous one 
        // wasn't used in this step, skipping this avoids redundant calculations.
        if (i > 0 && b[i] == b[i - 1] && !used[i - 1]) continue;

        // Check divisibility
        if (b[i] % prev == 0) {
            int next_val = b[i] / prev;

            // Check constraint: array elements must be <= 100
            if (next_val >= 1 && next_val <= 100) {
                
                // Move forward
                used[i] = true;
                a[idx] = next_val;

                solve(idx + 1);

                // If found in the deeper recursion, return immediately
                if (found) return;

                // Backtrack
                used[i] = false;
            }
        }
    }
}

int main() {
    // Optimization for faster I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (cin >> n) {
        b.resize(n - 1);
        for (int i = 0; i < n - 1; ++i) {
            cin >> b[i];
        }

        // Sort b to handle duplicates efficiently
        sort(b.begin(), b.end());

        a.resize(n);
        used.assign(n - 1, false);

        // Try every possible start value for a[0]
        for (int start_val = 1; start_val <= 100; ++start_val) {
            a[0] = start_val;
            solve(1); // Start recursing from index 1
            if (found) break;
        }

        if (!found) {
            cout << "No" << endl;
        }
    }

    return 0;
}