#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAXN = 1e5+7;

int arr[MAXN];
int tree[4*MAXN];

int build(int node, int l, int r){
    if(l == r) return tree[node] = 0;
    int m = (l+r)/2;
    return tree[node] = build(2*node, l, m) + build(2*node+1, m+1, r);
}
    
int query(int node, int l, int r, int a, int b){
    if(b < l or r < a) return 0;
    if(a <= l and r <= b) return tree[node];
    int m = (l+r)/2;
    return query(2*node, l, m, a, b) + query(2*node+1, m+1, r, a, b);
}

void update(int node, int l, int r, int i, int x){
    if(i < l or r < i) return;
    if(l == r){
        tree[node] += x;
        return;
    }
    int m = (l+r)/2;
    update(2*node, l, m, i, x);
    update(2*node+1, m+1, r, i, x);
    tree[node] = tree[2*node] + tree[2*node+1];
}

signed main(){
    winton;
    int n, m;
    cin >> n >> m;
    build(1, 0, n-1);
    while(m--){
        int op;
        cin >> op;
        if (op == 1){
            int l, r, x;
            cin >> l >> r >> x;
            update(1, 0, n-1, l, x);
            if (r <= n) update(1,0,n-1,r, -x);
        }
        else {
            int i;
            cin >> i;
            cout << query(1, 0, n-1, 0, i) << endl;
        }
    }
}