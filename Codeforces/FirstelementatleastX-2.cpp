#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAXN = 1e5+7;

int arr[MAXN], tree[4*MAXN];

int build(int node, int l, int r){
    if(l == r) return tree[node] = arr[l];
    int m = (l+r)/2;
    return tree[node] = max(build(2*node, l, m), build(2*node+1, m+1, r));
}
    
int query(int node, int l, int limit, int r, int x){
    //cout << "l: " << l << " node: " << node << " r: " << r << endl;
    if (r < limit || tree[node] < x) return -1;
    if (l == r) return l;
    int m = (l+r)/2;
    int esq = query(2*node, l, limit, m, x);
    if (esq != -1) return esq;
    return query(2*node+1, m+1, limit, r, x);
}

void update(int node, int l, int r, int i, int x){
    if(i < l or r < i) return;
    if(l == r){
        tree[node] = x;
        return;
    }
    int m = (l+r)/2;
    update(2*node, l, m, i, x);
    update(2*node+1, m+1, r, i, x);
    tree[node] = max(tree[2*node], tree[2*node+1]);
}

signed main(){
    winton;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> arr[i];
    build(1, 0, n-1);
    //for (int i = 0; i < 10; i++)cout<<i<<" : "<<tree[i]<<endl;
    while(m--){
        //for (int i = 0; i < 10; i++)cout<<i<<" : "<<tree[i]<<endl;
        int op;
        cin >> op;
        if (op == 1){
            int i, x;
            cin >> i >> x;
            update(1, 0, n-1, i, x);
        }
        else {
            int x, l;
            cin >> x >> l;
            cout << query(1, 0, l, n-1, x) << endl;
        }
    }
}