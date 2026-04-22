#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAXN = 2e5+7;

int arr[MAXN], tree[4*MAXN], esq[MAXN], visited[MAXN];

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
        tree[node] = !tree[node];
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
    vector<int> reversed;
    for (int i = 0; i < 2*n; i++){
        cin >> arr[i];
        reversed.push_back(arr[i]);
    }
    vector<int> ans(n, 0);
    for (int i = 0; i < 2*n; i++){
        if (!visited[arr[i]]){
            esq[arr[i]] = i;
            visited[arr[i]] = 1;
            update(1, 0, 2*n-1, i);
        }
        else {
            update(1, 0, 2*n-1, esq[arr[i]]);
            ans[arr[i]-1] += (query(1, 0, 2*n-1, esq[arr[i]], i));
        }
    }
    memset(visited, 0, sizeof(visited));
    memset(esq, 0, sizeof(esq));
    memset(tree, 0, sizeof(tree));
    reverse(all(reversed));

    for (int i = 0; i < 2*n; i++)arr[i]=reversed[i];
    
    for (int i = 0; i < 2*n; i++){
        if (!visited[arr[i]]){
            esq[arr[i]] = i;
            visited[arr[i]] = 1;
            update(1, 0, 2*n-1, i);
        }
        else {
            update(1, 0, 2*n-1, esq[arr[i]]);
            ans[arr[i]-1] += (query(1, 0, 2*n-1, esq[arr[i]], i));
        }
    }
    
    for (auto u : ans) cout << u << " ";cout<<endl;
}