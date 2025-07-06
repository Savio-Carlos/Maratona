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
    winton;
    int n, m;
    cin >> n >> m;
    map<vector<int>, int> freq;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        vector<int> sig(m / 2);
        for (int j = 0; j < m / 2; j++) {
            int d = ((s[m-j-1]-'a') - (s[j]-'a')) % 26;
            sig[j] = (d + 26) % 26;
        }
        freq[sig]++;
    }
    int ans = 0;
    for (auto &[sig, cnt] : freq) {
        vector<int> c(m / 2);
        for (int j = 0; j < sig.size(); ++j) {
            c[j] = (26 - sig[j]) % 26;
        }
        auto it = freq.find(c);
        if (it != freq.end()) {
            int x = it->second;
            ans += cnt * x;
        }
    }
    cout << ans << endl;
}