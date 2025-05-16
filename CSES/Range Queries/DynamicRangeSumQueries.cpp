#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAX = 2e5+7;

int n, q, tree[4*MAX], arr[MAX];

void build (int node, int l, int r){
    if (l == r) {
        tree[node] = arr[l];
        return;
    }
    int m = (l+r)/2;
    build(node*2, l, m);
    build(node*2+1, m+1, r);
    tree[node] = tree[node*2] + tree[node*2+1];
}

void update(int node, int l, int r, int i, int x){
    if (i < l || i > r) return;
    if (l == r){
        tree[node] = x;
        return;
    }
    int m = (l+r)/2;
    update(node*2, l, m, i, x);
    update(node*2+1, m+1, r, i, x);
    tree[node] = tree[node*2] + tree[node*2+1];
}

int query (int node, int l, int r, int a, int b){
    if (r < a || b < l) return 0;
    if (l >= a && r <= b) return tree[node];
    int m = (l+r)/2;
    return query(node*2, l, m, a, b) + query(2*node+1, m+1, r, a, b);
}
    
signed main(){
    winton;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)cin>>arr[i];   
    build(1,1,n);
    //for (int i = 0; i < 2*n; i++)cout<<tree[i]<<" ";   
    while(q--){
        int op;
        cin >> op;
        if (op == 1){
            int k, u;
            cin >> k >> u;
            update(1,1,n,k,u);
        }
        else {
            int a,b;
            cin >> a >> b;
            cout << query(1,1,n,a,b) << endl;
        }
    }
}