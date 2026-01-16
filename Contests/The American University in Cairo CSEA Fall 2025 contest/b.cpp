#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
// #define int long long
#define ld long double

#define winton ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    int x = 0;
    while ((1 << x) < n){
        int st = (1 << x) - 1;
        int en = min((1 << (x+1)) - 1, n);
        // cout << "st: " << st << endl;
        // cout << "en: " << en << endl;
        sort(s.begin() + st, s.begin() + en);
        x++;
    }
    cout << s << endl;
}

signed main(){
    winton;
    int t;
    cin >> t;   
    while(t--) solve();
}