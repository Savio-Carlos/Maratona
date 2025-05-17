#include <bits/stdc++.h>
using namespace std;
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long
#define ld long double
const int MOD = 1e9+7;

signed main() {
    winton;
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < s.size(); i++){
        ans += (s[i] - '0');
    }
    cout << ans%3  << endl;
}