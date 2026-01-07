#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

void dbg_out() { cerr << endl;}
template<typename H, typename... T>
void dbg_out(H h, T... t) {cerr << ' ' << h; dbg_out(t...);}

// #define DEBUG

#if defined(DEBUG)
#define fastio (void)0
#define debug(...) cerr << #__VA_ARGS__ << ':';
dbg_out(__VA_ARGS__);
#else
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define debug(...) (void)0
#endif

signed main(){
    fastio;
    int r, n;
    cin >> r >> n;
    int sum1 = 0, sum2 = r;
    bool pos1 = false;
    bool pos2 = false;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        sum1 += x;
        sum2 += x;

        sum1 = min(sum1, r);
        sum1 = max(sum1, 0LL);
        sum2 = min(sum2, r);
        sum2 = max(sum2, 0LL);
        if (sum1 >= r) pos1 = true;
        if (sum2 <= 0) pos2 = true;
    }
    if (pos1) cout << sum1 << endl;
    else if (pos2) cout << sum2 << endl;
    else cout << "uncertain\n";
}