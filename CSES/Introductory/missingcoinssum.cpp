#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)

signed main() {
    winton;
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &u : a) cin >> u; 
    sort(all(a));
    int sum = 0;
    for (auto u : a) {
        if (u > sum + 1) break;
        sum += u;
    }
    cout << sum + 1 << endl;
}