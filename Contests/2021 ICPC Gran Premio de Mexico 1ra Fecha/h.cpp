#include <bits/stdc++.h>
using namespace std;

#define endl '\n' 
#define winton ios_base::sync_with_stdio(0),cin.tie(0)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int long long
#define ld long double

#define debug(x) cerr<<#x<<": " << x << endl;
#define vdebug(x) cerr << #x << ": "; for(auto i : x) cerr << i << " "; cerr << endl;

const int MOD = 1e9+9;
const int P = 31;

struct hashing {
    vector<int> h, p_pow;
    string s;
    int n;
    
    hashing(string _s) : n(_s.size()), s(_s), h(_s.size()+1, 0), p_pow(_s.size(), 0) {} 

    void build(){
        p_pow[0] = 1; 

        for (int i = 1; i < n; i++) p_pow[i] = (p_pow[i-1] * P) % MOD;
        for (int i = 0; i < s.size(); i++) h[i+1] = (h[i] + (s[i] - '0' + 1) * p_pow[i]) % MOD;
    }
    

    int get_hash(int l, int len){
        int r = l + len;
        return ((h[r] + MOD - h[l]) % MOD);
    }

    bool equal_substrings(int len) {
        if (!len) return true;

        int h1 = get_hash(0, len);
        int h2 = get_hash(n - len, len);

        int left  = (h1 * p_pow[n-len]) % MOD;
        int right = (h2) % MOD;
        return left == right;
    }
};

signed main(){
    winton;
    string s;
    int b;
    cin >> b >> s;
    if (b >= s.size()){
        cout << 1 << endl;
        return 0;
    }
    hashing hash(s);
    hash.build();
    int n = s.size();
    int ans = n;
    for (int sz = 2; sz <= b and sz <= n; sz++){
        vector<map<int,int>> dp(n+1);
        
        for (int i = 1; i+sz <= n; i++){
            int st = i, en = i+sz-1;
            int h = hash.get_hash(i-1, sz);

            if (!dp[i-1].count(h)) dp[i-1][h] = 0;
            dp[en][h] = dp[i-1][h] + 1;
            for (auto [u,v] : dp[i-1]) dp[i][u] = max(dp[i][u], v);
        
        }
        for (auto [u,v] : dp[n]){
            ans = min(n-v*sz+v, ans);
            debug(u);
            debug(v);
            debug(sz);
        } 
    }
    cout << ans << endl;
}