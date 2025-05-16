#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAXN = 1e5+7;
const int INF = INT_MAX;

struct item {
    int seg, pfx, sfx, sum;
};

int arr[MAXN];
item tree[4*MAXN];

item merge (item a, item b){
    return {
        max({a.seg,b.seg,a.sfx+b.pfx}),
        max(a.pfx,a.sum + b.pfx),
        max(b.sfx,b.sum+a.sfx),
        a.sum+b.sum
    };
}

item single(int a){
    if (a > 0) return {a,a,a,a};
    return {0,0,0,a};
}

item build(int node, int l, int r){
    if(l == r) return tree[node] = single(arr[l]);
    int m = (l+r)/2;
    return tree[node] = merge(build(2*node, l, m), build(2*node+1, m+1, r));
}

item query(int node, int l, int r, int a, int b){
    if(b < l or r < a) return {0,0,0,0};
    if(a <= l and r <= b) return tree[node];
    int m = (l+r)/2;
    item p1 = query(2*node, l, m, a, b);
    item p2 = query(2*node+1, m+1, r, a, b);
    return merge(p1,p2);
}

void update(int node, int l, int r, int i, int x){
    if(i < l or r < i) return;
    if(l == r){
        tree[node] = single(x);
        return;
    }
    int m = (l+r)/2;
    update(2*node, l, m, i, x);
    update(2*node+1, m+1, r, i, x);
    tree[node] = merge(tree[2*node], tree[2*node+1]);
}

signed main(){
    winton;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    build(1, 0, n-1);
    item ans = query(1, 0, n-1, 0, n-1);
    cout << ans.seg << endl;
    while(m--){
        int a, b;
        cin >> a >> b;
        update(1, 0, n-1, a, b);
        item ans = query(1, 0, n-1, 0, n-1);
        cout << ans.seg << endl;
    }
}