#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAXN = 1e5+7;

int p, arr[MAXN], tree[4*MAXN];

int build(int node, int l, int r){
    if(l == r) return tree[node] = arr[l];
    int m = (l+r)/2;
    return tree[node] = build(2*node, l, m) + build(2*node+1, m+1, r);
}
    
int query(int node, int l, int r, int k){
    if (l == r) return l;
    int m = (l+r)/2;
    if (tree[2*node] > k) return query(2*node, l, m, k);
    else return query(2*node+1, m+1, r, k - tree[2*node]);
}

void update(int node, int l, int r, int i){
    if(i < l or r < i) return;
    if(l == r){
        tree[node] = !(tree[node]);
        return;
    }
    int m = (l+r)/2;
    update(2*node, l, m, i);
    update(2*node+1, m+1, r, i);
    tree[node] = tree[2*node] + tree[2*node+1];
}

signed main(){
    winton;
    int n, m;
    cin >> n >> m;
    float f = ceil(log2(n));
    p = f;
    p = (1<<p);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    build(1, 0, n-1);

    while(m--){
        int op;
        cin >> op;
        if (op == 1){
            int i;
            cin >> i;
            update(1, 0, n-1, i);
        }
        else {
            int k;
            cin >> k;
            cout << query(1, 0, n-1, k) << endl;
        }
    }
}