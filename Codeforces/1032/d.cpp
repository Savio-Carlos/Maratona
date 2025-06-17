#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define debug(x) cout << #x << " = " << x << "\n";
const int MAX = 2e5+7;
const int INF = INT_MAX;

struct operacao {
    int t;
    int idx;
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(auto &u : a) cin >> u;
    for(auto &u : b) cin >> u;

    vector<operacao> ops;

    for (int i = 0; i < n; i++) {
        if (a[i] > b[i]) {
            swap(a[i], b[i]);
            ops.push_back({3, i + 1});
        }
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                ops.push_back({1, j + 1});
            }
        }
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (b[j] > b[j + 1]) {
                swap(b[j], b[j + 1]);
                ops.push_back({2, j + 1});
            }
        }
    }
    cout << ops.size() << endl;
    for (auto& op : ops) {
        cout << op.t << " " << op.idx << endl;
    }
}

signed main() {
   winton;
    int t;
    cin >> t;
    while (t--) solve();
}