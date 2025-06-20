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

signed main() {
    winton;
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    vector<int> cnt(256, 0);
    int mask = 0;
    cnt[0] = 1;
    for (char c : s) {
        int chab = c - 'a';
        mask ^= (1 << chab);
        ans += cnt[mask];
        for (int k = 0; k < 8; ++k) {
            int target_mask = mask ^ (1 << k);
            ans += cnt[target_mask];
        }
        cnt[mask]++;
    }

    cout << ans << endl;
}