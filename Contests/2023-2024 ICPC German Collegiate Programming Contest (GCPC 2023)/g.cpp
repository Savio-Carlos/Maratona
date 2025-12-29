#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL)


signed main(){
    fastio;
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i<=9; i++){
        string c = to_string(i);
        for (int j = 0; j < 9; j++){
            int num = stoll(c);
            if (num <= n) ans++;
            // cout << "num: " << num << endl;
            c += to_string(i);
        }
    }
    string tot = to_string(n);
    ans += max(1LL, (int)tot.size()-1LL);
    cout << ans << endl;
}