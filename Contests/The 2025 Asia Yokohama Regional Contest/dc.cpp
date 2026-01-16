#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
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
    #define fastio ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL)
    #define debug(...) (void)0
#endif


int fastExpo(int base, int exp) {
    int res = 1;
    while(exp) {
        if (exp & 1) res = res * base;
        base = base * base;
        exp >>= 1;
    }
    return res;
}

signed main(){
    fastio;
    int n;
    cin >> n;
    string s = to_string(n);
    debug(s);
    string ans = "";
    for (int i = 0; i < s.size(); i++){
        int minus = fastExpo(10, i);
        string st = to_string(n - minus);
        string end = to_string(minus);
        string pos = st + end;
        if (ans.size() < pos.size()) ans = pos;
        if (ans.size() == pos.size()){
            ans = max(ans,pos);
        }
    }
    cout << ans << endl;
}