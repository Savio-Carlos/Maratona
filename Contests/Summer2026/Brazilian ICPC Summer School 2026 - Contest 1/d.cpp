#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

void dbg_out() {cerr << endl;}
template<typename H, typename... T>
void dbg_out(H h, T... t) {cerr << ' ' << h; dbg_out(t...);}

#define DEBUG

#if defined(DEBUG)
    #define fastio (void)0
    #define debug(...) cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__);
#else 
    #define fastio ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL)
    #define debug(...) (void)0
#endif

const int MAX = 3e4+5;
const int MAXQ = 2e5+7;
const int MAXE = 1e6+7;

struct Query {
    int l, r, id;
};

int n, q;
int a[MAX], bit[MAX];
int last[MAXE];
int answers[MAXQ];
vector<Query> queries;

void update(int idx, int val) {
    for (; idx <= n; idx += idx & -idx) bit[idx] += val;
}

int query(int idx) {
    int sum = 0;
    for (; idx > 0; idx -= idx & -idx) sum += bit[idx];
    return sum;
}

signed main(){
    fastio;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    cin >> q;
    for(int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;
        queries.push_back({l, r, i});
    }

    sort(all(queries), [](const Query& a, const Query& b){
        return a.r < b.r;
    });
    
    int cur = 0;
    for(int i = 1; i <= n; i++) {
        if (last[a[i]] != 0) {
            update(last[a[i]], -1);
        }
        debug(last[a[i]], i, a[i], cur);
        update(i, 1);
        last[a[i]] = i;
        while(cur < q && queries[cur].r == i) {
            answers[queries[cur].id] = query(i) - query(queries[cur].l - 1);
            cur++;
        }
    }

    for(int i = 0; i < q; i++) {
        cout << answers[i] << endl;
    }
}