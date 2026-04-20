#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int long long
#define ld long double
#define endl '\n'

#define winton ios_base::sync_with_stdio(false),cin.tie(0)

signed main(){
    winton;
    int n, k;
    cin >> n >> k;

    int max_safe = 1;
    int min_broken = k;

    for (int i = 0; i < n; i++){
        int x;
        string s;
        cin >> x >> s;
        if (s == "SAFE") max_safe = max(max_safe, x);
        else min_broken = min(min_broken, x);
    }

    cout << max_safe + 1 << " " << min_broken - 1 << endl;
}

