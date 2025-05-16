#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAX = 2e5+7;
const int LOG = 20;

int n, q, tree[4*MAX], arr[MAX], answers[MAX];
map<int, vector<pair<int,int>>> queries;
map<int,int> last;


int query(int node, int l, int r, int a, int b){
    if(b < l or r < a) return 0;
    if(a <= l and r <= b) {
        //cout << "node: " << node << " l: " << l << " r: " << r << " a: " << a << " b: " << b  << " valor: " << tree[node]<< endl;
        return tree[node];
    
    }
        int m = (l+r)/2;
    return query(2*node, l, m, a, b) + query(2*node+1, m+1, r, a, b);
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
    tree[node] = tree[2*node] + tree[2*node+1];
}

signed main() {
    winton;
    cin >> n >> q;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for (int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;
        queries[a].push_back({b,i});
    }
    for (int i = n-1; i >= 0; i--){
        int cur = arr[i];
        if (last.count(cur) != 0){
            update(1,0,n-1, last[cur], 0);
        }
        update(1,0,n-1,i,1);
        last[cur] = i;
        for (auto [b,idx] : queries[i+1]){
            //cout << i << " " << b << " " << idx << endl;

            answers[idx] = query(1,0,n-1, i, b-1);
        }
        //for (int i = 0; i < 2*n; i++){cout<<tree[i]<<" ";}cout<<endl;
    }
    for (int i = 0; i < q; i++){
        cout << answers[i] << endl;
    }
}