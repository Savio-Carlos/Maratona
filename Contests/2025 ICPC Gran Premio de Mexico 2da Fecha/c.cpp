#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

void dbg_out() { cerr << endl; }
template<typename H, typename... T> 
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }

// #define DEBUG

#if defined(DEBUG)
    #define fastio (void)0
    #define debug(...) cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__);
#else
    #define fastio ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(...) (void)0
#endif

const int MOD = 998244353;

int fastexpo(int a, int b){
    int res = 1;
    while(b > 0){
        if(b&1) res = (res*a)%MOD;
        a = (a*a)%MOD;
        b >>=1;
    }
    return res;
}

signed main(){
    fastio;
    int n; cin >> n;
    map<int, int> freq;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        freq[x]++;
    }

    int ans = 1;
    for(auto [u, cnt] : freq){
        int v = (fastexpo(2, cnt) - (cnt+1) + MOD)%MOD;
        ans = (ans + v)%MOD;
    }
    cout << ans << endl;
}