#include <bits/stdc++.h>
using namespace std;
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long
#define ld long double
const int MAXN = 1e9+7;

signed main() {
    winton;
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0, mx = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
        mx = max(mx, a[i]);
    }
    if (sum - mx >= mx && sum%2 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
}