//Query de Segtree Offline

int n, tree[4*MAX];

int query (int node, int l, int r, int a, int b){
    if (b < l || r < a) return 0;
    if (l >= a && r <= b)  return tree[node];
    int m = (l+r)/2; 
    return query(node*2, l, m, a, b) + query(node*2+1, m+1, r, a, b);
}

void update(int node, int l, int r, int i, int x){
    if (i < l or i > r) return;
    if (l == r) {
        tree[node]=x;
        return;
    }
    int m = (l+r)/2;
    update(node*2, l, m, i, x);
    update(node*2+1, m+1, r, i, x);
    tree[node] = tree[node*2] + tree[node*2+1];
}

signed main(){
    winton;
    int q;
    cin >> n >> q;
    vector<pair<int,int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    vector<tuple<int,int,int,int>> queries;
    for (int i = 0; i < q; i++){
        int l, r, m;
        cin >> l >> m >> r;
        if (a[l-1].first < m && r > 0){
            queries.push_back ({m, l, l+r-1, i});
        }
    }
    sort(rall(a));
    sort(rall(queries));
    int pos = 0;
    vector<int>ans(q,0);
    for (auto [m,l,r,i] : queries){
        while (pos < n && a[pos].first >= m){
            // debug(m);
            // debug(l);
            // debug(r);
            // debug(a[pos].second);
            update(1,0,n-1,a[pos].second,1);
            pos++;
        }
        ans[i] = query(1,0,n-1,l,r);
        // cout << tree[8] << " " << tree[9] << " ";
        // for (int i = 5; i <= 7; i++)cout << tree[i] << " ";
        // cout << endl;
    }
    for (auto u : ans) cout << u << endl;
}
