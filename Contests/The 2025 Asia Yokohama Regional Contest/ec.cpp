#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

void dbg_out() { cerr << endl; }
template<typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }

#define DEBUG

#if defined(DEBUG)
    #define fastio (void)0
    #define debug(...) cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__);
#else
    #define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
    #define debug(...) (void)0
#endif

pair<int,int> solve_base(int A, int B, int C, int k) {
    int l = 1, r = max(A, k), ans = -1;

    while (l <= r) {
        int mid = l + (r - l) / 2;

        __int128 f1 = mid;
        __int128 f2 = (__int128)B * mid / A;
        __int128 f3 = (__int128)C * mid / A;

        __int128 prod = f1;
        prod = min(prod, (__int128)k);
        prod *= f2;
        prod = min(prod, (__int128)k);
        prod *= f3;
        prod = min(prod, (__int128)k);

        if (prod >= k) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }

    int g = gcd(A, ans);
    return {A / g, ans / g};
}

bool better(pair<int,int> a, pair<int,int> b) {
    return (__int128)a.first * b.second > (__int128)b.first * a.second;
}

void solve() {
    int a, b, c, k;
    cin >> a >> b >> c >> k;

    auto x1 = solve_base(a, b, c, k);
    auto x2 = solve_base(b, a, c, k);
    auto x3 = solve_base(c, a, b, k);

    pair<int,int> ans = x1;
    if (better(x2, ans)) ans = x2;
    if (better(x3, ans)) ans = x3;

    cout << ans.first << " " << ans.second << endl;
}

signed main() {
    fastio;
    int t;
    cin >> t;
    while (t--) solve();
}
