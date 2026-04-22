#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAXN = 2e5+7;

int tree[4*MAXN];

int build(int node, int l, int r){
    if (l == r) return tree[node] = 1;
    int m = (l+r)/2;
    return tree[node] = build(node*2, l, m) + build(node*2+1, m+1, r);
}

int query(int node, int l, int r, int k){
    if (l == r) return l;
    int m = (l+r)/2;
    if (tree[node*2+1] > k) return query(node*2+1, m+1, r, k);
    return query(node*2, l, m, k - tree[node*2+1]);
}
void update(int node, int l, int r, int i){
    if (i < l or i > r) return;
    if (l == r) {
        tree[node]=0;
        return;
    }
    int m = (l+r)/2;
    update(node*2, l, m, i);
    update(node*2+1, m+1, r, i);
    tree[node] = tree[node*2] + tree[node*2+1];
}


signed main(){
    winton;
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &u : a) cin >> u;
    vector<int> ans(n);
    build(1,0,n-1);
    for (int i = n; i > 0; i--){
        int x = query(1,0,n-1,a[i-1]);
        update(1,0,n-1,x);
        ans[i-1] = (x+1);
    }
    for (auto u : ans) cout << u << " ";
    cout << endl;
}