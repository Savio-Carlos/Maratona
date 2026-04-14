#include <bits/stdc++.h>
using namespace std;
#define int long long

bool interesting(int x) {
    string s = to_string(x);
    int n = s.size();
    for (int d = 0; d <= 9; d++) {
        int cnt = count(s.begin(), s.end(), '0' + d);
        if (2 * cnt >= n) return true;
    }
    return false;
}

signed main() {
    int l, r;
    cin >> l >> r;
    int ans = 0;
    for (int i = l; i <= r; i++) {
        if (interesting(i)) ans++;
    }
    cout << ans << endl;
}
