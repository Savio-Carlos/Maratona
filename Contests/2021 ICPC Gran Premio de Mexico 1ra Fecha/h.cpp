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
    
    hashing(string _s) : n(_s.size()), s(_s), h(_s.size()+1, 0), p_pow(_s.size()+1, 0) {} 

    void build(){
        p_pow[0] = 1; 

        for (int i = 1; i < n; i++) p_pow[i] = (p_pow[i-1] * P) % MOD;
        for (int i = 0; i < s.size(); i++) h[i+1] = (h[i]*P + (s[i] - '0' + 1)) % MOD;
    }
    

    int get_hash(int l, int len){
        int r = l + len;
        return (h[l+len] - (h[l]*p_pow[len] % MOD) + MOD) % MOD;
    }

    bool equal_substrings(int len) {
        if (!len) return true;

        int h1 = get_hash(0, len);
        int h2 = get_hash(n - len, len);
        return h1 == h2;
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
        map<int,pair<int,int>> dp;

        for (int i = 0; i+sz-1 < n; i++){
            int h = hash.get_hash(i, sz);

            auto &e = dp[h];
            if (e.second <= i){
                e.first++;
                e.second = i+sz;
            }
        }
        for (auto &[u,v] : dp) ans = min(n-v.first*sz+v.first, ans);
    }
    cout << ans << endl;
}