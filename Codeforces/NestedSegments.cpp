#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAXN = 2e5+7;

int arr[MAXN], tree[4*MAXN];

int build(int node, int l, int r){
    if(l == r) return tree[node] = arr[l];
    int m = (l+r)/2;
    return tree[node] = build(2*node, l, m) + build(2*node+1, m+1, r);
}
    
int query(int node, int l, int r, int a, int b){
    if(b < l or r < a) return 0;
    if(a <= l and r <= b) return tree[node];
    int m = (l+r)/2;
    return query(2*node, l, m, a, b) + query(2*node+1, m+1, r, a, b);
}

void update(int node, int l, int r, int i){
    if(i < l or r < i) return;
    if(l == r){
        tree[node] = 1;
        return;
    }
    int m = (l+r)/2;
    update(2*node, l, m, i);
    update(2*node+1, m+1, r, i);
    tree[node] = tree[2*node] + tree[2*node+1];
}

signed main(){
    winton;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++){
        ans[arr[i]-1] = query(1, 0, n-1, arr[i-1], n-1);
        update(1, 0, n-1, arr[i]-1);
    }
    for (auto u : ans) cout << u << " ";cout<<endl;
}