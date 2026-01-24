#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)

const int MAX = 3e5+7;

int a[MAX];

namespace SegTree {
	int tree[4*MAX], lazy[4*MAX];
	int n, *v;

	int build(int node=1, int l=0, int r=n-1) {
		lazy[node] = 0;
		if (l == r) return tree[node] = v[l];
		int m = (l+r)/2;
		return tree[node] = min(build(2*node, l, m), build(2*node+1, m+1, r));
	}
	void build(int n2, int* v2) {
		n = n2, v = v2;
		build();
	}
	void prop(int node, int l, int r) {
		tree[node] += lazy[node];
		if (l != r) lazy[2*node] += lazy[node], lazy[2*node+1] += lazy[node];
		lazy[node] = 0;
	}
	int query(int a, int b, int node=1, int l=0, int r=n-1) {
		prop(node, l, r);
		if (a <= l and r <= b) return tree[node];
		if (b < l or r < a) return 1e9;
		int m = (l+r)/2;
		return min(query(a, b, 2*node, l, m),query(a, b, 2*node+1, m+1, r));
	}
	int update(int a, int b, int x, int node=1, int l=0, int r=n-1) {
		prop(node, l, r);
		if (a <= l and r <= b) {
			lazy[node] += x;
			prop(node, l, r);
			return tree[node];
		}
		if (b < l or r < a) return tree[node];
		int m = (l+r)/2;
		return tree[node] = min(update(a, b, x, 2*node, l, m), update(a, b, x, 2*node+1, m+1, r));
	}
}

void solve(){
    int n;
    string s;
    cin >> n >> s;
    int sum = 0;
    for (int i = 0; i < n; i++){
        a[i] = 0;
        if (s[i] == '(') sum++;
        else sum--;
        a[i] = sum;
    }
    SegTree::build(n, a);
    int q;
    cin >> q;
    while(q--){
        int v;
        cin >> v;
        if (!v){
            if (SegTree::query(0, n-1) >= 0  && sum == 0) cout << "YES" << endl;
            else cout << "NO" << endl; 
            continue;
        }
        --v;
        if (s[v] == ')'){
            SegTree::update(v, n-1, 2);
            s[v] = '(';
            sum += 2;
        }
        else {
            SegTree::update(v, n-1, -2);
            s[v] = ')';
            sum -= 2;
        }
    }

}

signed main(){
    winton;
    for (int i = 1; i <= 10; i++){
        cout << "Test " << i << ":" << endl;
        solve();
    }
}