#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(a) ((int)a.size())
#define endl '\n'
#define int long long
#define ld long double

void debug_out(string s, int line) {cerr << endl; }
template<typename H, typename... T>
void debug_out(string s, int line, H h, T... t){
    do{
        cerr << s[0]; s = s.substr(1);
    }
    while (sz(s) and s[0] != ',');
    cerr << " = " << h;
    debug_out(s, line, t...);
}

#define DEBUG
#if defined(DEBUG)
    #define winton (void)0
    #define debug(...) debug_out(#__VA_ARGS__, __LINE__, __VA_ARGS__)
    #define vdebug(a) cerr << #a << " = ["; for(auto it = (a).begin(); it != (a).end(); ++it) cerr << *it << (next(it) == (a).end() ? "" : ", "); cerr << "]" << endl;
#else
    #define winton ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void)0
    #define vdebug(x) (void)0
#endif

const int MAX = 2e5+7;
const int MOD = 1e9+7;
const int INF = LLONG_MAX;

ld fastExpo(ld base, int exp) {
    ld res = 1;
    while(exp) {
        if (exp & 1) res = res * base;
        base = base * base;
        exp >>= 1;
    }
    return res;
}

signed main(){
    winton;
    int n;
    cin >> n;
    vector<ld> a(n);
    for (auto &u : a) cin >> u;
    sort(all(a));
    ld ans = 0;
    //funciona se todo ai for unico
    for (int i = 0; i < n; i++){
        ans += a[i] * ((fastExpo(2, i) - fastExpo(2, n-i-1)) / (fastExpo(2, n) - (ld)1));
        debug(ans);
    }
    debug(ans);
}