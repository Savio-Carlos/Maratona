#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
const int MAX = 1e6+7;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f3f3f3f3fLL;

int n, tree[4*MAX], on[4*MAX], valid[4*MAX], si[MAX];
bool lazy[4*MAX];

void build(int node, int l, int r){
    lazy[node] = false;
    if (l == r){
        if (si[l] == -1){
            on[node] = 0;
            valid[node] = 0;
        }
        else{
            valid[node] = 1;
            on[node] = si[l];
        }
        return;
    }
    int m = (l+r)/2;
    build(node*2, l, m);
    build(node*2+1, m+1, r);
    valid[node] = valid[node*2] + valid[node*2+1];
    on[node] = on[node*2] + on[node*2+1];
}
void flip(int node){
    on[node] = valid[node] - on[node];
    lazy[node] = !lazy[node];
}

void prop(int node){
    if (lazy[node]){
        flip(node*2);
        flip(node*2+1);
        lazy[node] = false;
    }
}

void update(int node, int l, int r, int a, int b){
    if(b < l or r < a) return;
    if(a <= l && r <= b){
        flip(node);
        return;
    }
    prop(node);
    int m = (l+r)/2;
    update(2*node, l, m, a, b);
    update(2*node+1, m+1, r, a, b);
    on[node] = on[node*2] + on[node*2+1];
}

signed main(){
    winton;
    int m;
    cin >> n >> m;
    int tot = 0;
    for (int i = 0; i < n; i++){
        int pi;
        cin >> si[i] >> pi;
        tot += pi;
    }

    build(1,0,n-1);

    while(m--){
        char tp;
        cin >> tp;
        if (tp == 'W'){
            int l, r;
            cin >> l >> r;
            update(1,0,n-1,l,r);
        }
        else {
            int val;
            cin >> val;
            tot += val * on[1];
        }
    }
    cout << tot << endl;

}