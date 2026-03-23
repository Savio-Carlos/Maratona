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

struct DSU {
    vector<int> comp, sz;
    DSU(int n) : comp(n), sz(n,1){
        iota(all(comp), 0);
    }

    int find(int u) {
        if (u == comp[u]) return u;
        return comp[u] = find(comp[u]);
    }
    void unite(int a, int b){
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a,b);
        sz[a] += sz[b];
        comp[b] = a;
    }
};

signed main(){
    fastio;
    int n;
    cin >> n;
    vector<pair<int,int>> a(n);
    int s = 0, p = 0;
    for (int i = 0; i < n; i++){
        auto &[pp, ss] = a[i];
        cin >> pp >> ss;
        p += pp;
        s += ss;
    }
    int ans = 0;
    for (int i = 0; i < n; i++){
        auto &[pp, ss] = a[i];
         
        int outros = s - ss;
        int diff = abs(pp-outros);
        if (pp > outros){
            s += diff;
            p -= pp;
            s -= pp;
            ans += diff;
        }
    }
    cout << ans + abs(p-s) << endl;
}