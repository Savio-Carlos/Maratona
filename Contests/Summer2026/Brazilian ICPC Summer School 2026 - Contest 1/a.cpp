#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

void dbg_out() {cerr << endl;}
template<typename H, typename... T>
void dbg_out(H h, T... t) {cerr << ' ' << h; dbg_out(t...);}

// #define DEBUG

#if defined(DEBUG)
    #define fastio (void)0
    #define debug(...) cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__);
#else 
    #define fastio ios_base::sync_with_stdio(false), cout.tie(NULL) cin.tie(NULL)
    #define debug(...) (void)0
#endif

void solve(){
    string a, b;
    cin >> a >> b;
    reverse(all(a));
    reverse(all(b));

    int n = stoll(a);
    int m = stoll(b);
    int ans = n+m;
    debug(a, b, ans);
    string s = to_string(ans);
    reverse(all(s));
    int i = 0;
    while (i < s.size() && s[i] == '0') i++;
    debug(s,i);
    string r = s.substr(i);
    cout << r << endl;
}

signed main(){
    fastio;
    int t;
    cin >> t;
    while(t--) solve();
}