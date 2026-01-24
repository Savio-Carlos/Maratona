#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define winton ios_base::sync_with_stdio(0); cin.tie(0), cout.tie(0)

struct interval {
    int l, r;
};

bool compareintervals(const interval& a, const interval& b) {
    if (a.l != b.l) return a.l < b.l;
    return a.r > b.r;
}

void solve() {
    int n, m;
    while (cin >> n >> m && (n != 0 || m != 0)) {
        vector<interval> intervals(m);
        for (int i = 0; i < m; ++i) {
            int x, rd;
            cin >> x >> rd;
            int s = max(0LL, x - rd);
            int e = min(n, x + rd);
            intervals[i] = {s, e};
        }
        sort(all(intervals), compareintervals);
        priority_queue<int> pq;
        int cur = 0;
        int cnt = 0;
        int idx = 0;
        bool pos = true;
        while (cur < n) {
            while (idx < m && intervals[idx].l <= cur) {
                pq.push(intervals[idx].r);
                idx++;
            }
            if (pq.empty()) {
                pos = false;
                break;
            }
            int mx = pq.top();
            if (mx <= cur) {
                pos = false;
                break;
            }
            cur = mx;
            cnt++;
            while (!pq.empty()) pq.pop();
        }
        if (pos) cout << m - cnt << endl;
        else cout << -1 << endl;
    }
}

signed main() {
    winton;
    solve();
}
