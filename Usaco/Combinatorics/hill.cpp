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

int tree[4*MAX];

int build(int node, int l, int r){
    if (l == r){
        return tree[node] = 0;
    }
    int m = (l+r)/2;
    return tree[node] = build(node*2, l, m) + build(node*2+1, m+1, r);
}

int query (int node, int l, int r, int a, int b){
    if (b < l || r < a) return 0;
    if (l >= a && r <= b)  return tree[node];
    int m = (l+r)/2; 
    return query(node*2, l, m, a, b) + query(node*2+1, m+1, r, a, b);
}

void update(int node, int l, int r, int i, int x){
    if (i < l or i > r) return;
    if (l == r) {
        tree[node]+=x;
        return;
    }
    int m = (l+r)/2;
    update(node*2, l, m, i, x);
    update(node*2+1, m+1, r, i, x);
    tree[node] = tree[node*2] + tree[node*2+1];
}

signed main(){
    winton;
    int n;
    cin >> n;
    vector<int> a(n), lcnt(n), rcnt(n);
    for (auto &u : a) cin >> u;//Para numeros maiores que 1e9 fazer coordinate compression

    //contabilizar elementos a esquerda que sao menores que a[i]
    for (int i = 0; i < n; i++){
        int r = a[i];
        lcnt[i] = query(1,0,n-1, 0, r-1);
        update(1,0,n-1,r,1);
    }
    vdebug(lcnt);
    
    memset(tree, 0, sizeof(tree));
    
    //contabilizar elementos a direita que sao menores que a[i]
    for (int i = n-1; i; i--){
        int r = a[i];
        rcnt[i] = query(1,0,n-1, 0, r-1);
        update(1,0,n-1,r,1);
    }
    vdebug(rcnt);

    int ans = 0;
    for (int i = 1; i < n-1; i++){
        ans += (lcnt[i] * rcnt[i]);
    }
    cout << ans << endl;
}