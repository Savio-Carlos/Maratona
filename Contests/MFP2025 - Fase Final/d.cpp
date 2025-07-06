#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
const int MAX = 2e5+7;
const int MOD = 1e9+7;
const int INF = LLONG_MAX;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<int> in_row(n+1, 0);
    vector<int> in_col(n+1, 0);
    vector<vector<int>> for_row(n+1);
    
    for (int i = 0; i < m; i++) {
        int r, c;
        cin >> r >> c;
        in_row[r]++;
        in_col[c]++;
        for_row[r].push_back(c);
    }
    
    int initial_distinct_rows = 0;
    for (int i = 1; i <= n; i++) {
        if (in_row[i] > 0) initial_distinct_rows++;
    }
    
    vector<int> rows;
    for (int i = 1; i <= n; i++) {
        rows.push_back(i);
    }
    sort(rows.begin(), rows.end(), [&](int i, int j) {
        return in_row[i] > in_row[j];
    });
    
    set<int> a_set;
    int bound = 600;
    for (int a_val = 0; a_val <= min(n, bound); a_val++) {
        a_set.insert(a_val);
    }
    int low = max(0LL, initial_distinct_rows - bound/2);
    int high = min(n, initial_distinct_rows + bound/2);
    for (int a_val = low; a_val <= high; a_val++) {
        a_set.insert(a_val);
    }
    
    vector<int> a_vec(a_set.begin(), a_set.end());
    sort(a_vec.begin(), a_vec.end());
    
    vector<int> w(n+1, 0);
    int max_coverage = 0;
    int last_a_val = -1;
    
    for (int a_val : a_vec) {
        if (a_val == 0) {
            for (int col = 1; col <= n; col++) {
                w[col] = 0;
            }
            last_a_val = 0;
        } else {
            int start = last_a_val >= 0 ? last_a_val : 0;
            for (int idx = start; idx < a_val; idx++) {
                int r = rows[idx];
                for (int col : for_row[r]) {
                    w[col]++;
                }
            }
            last_a_val = a_val;
        }
        
        int A = 0;
        for (int idx = 0; idx < a_val; idx++) {
            A += in_row[rows[idx]];
        }
        
        vector<int> w_sorted;
        for (int col = 1; col <= n; col++) {
            w_sorted.push_back(w[col]);
        }
        sort(w_sorted.begin(), w_sorted.end(), greater<int>());
        vector<int> prefix(n+1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i+1] = prefix[i] + w_sorted[i];
        }
        
        for (int b_val = 0; b_val <= n; b_val++) {
            if (prefix[b_val] > 1e18) continue;
            int moves = a_val - A + (b_val * n - prefix[b_val]);
            if (moves <= k) {
                int coverage = a_val * n + (int)b_val * n - (int)a_val * b_val;
                if (coverage > max_coverage) {
                    max_coverage = coverage;
                }
            }
        }
    }
    
    cout << max_coverage << endl;
    
    return 0;
}