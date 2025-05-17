#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
#define int long long

signed main() {_
    string s;
    cin >> s;
    vector<int> suf(s.size() + 1, 0);
    vector<int> pre(s.size() + 1, 0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s1;
        cin >> s1;
        for (int j = 1; j <= s.size(); j++) {
            if (j <= s1.size() && s1.substr(s1.size() - j) == s.substr(0, j)) {
                suf[j]++;
            }
        }
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        string s2;
        cin >> s2;
        for (int j = 1; j <= s.size(); j++) {
            if (j <= s2.size() && s2.substr(0, j) == s.substr(s.size() - j)) {
                pre[j]++;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= s.size(); i++) {
        ans += suf[i] * pre[s.size() - i];
    }
    cout << ans << endl;

    return 0;
}
