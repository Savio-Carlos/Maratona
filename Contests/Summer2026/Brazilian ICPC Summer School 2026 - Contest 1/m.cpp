#include <bits/stdc++.h>
using namespace std;

 #define ll long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

void dbg_out() {cerr << endl;}
template<typename H, typename... T>
void dbg_out(H h, T... t) {cerr << ' ' << h; dbg_out(t...);}

// #define DEBUG

#if defined(DEBUG)
    #define fastio (void)0
    #define debug(...) cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__);
#else 
    #define fastio ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL)
    #define debug(...) (void)0
#endif

const int LOG = 30;
const int MAX = 1e5+7;

int a[MAX];

namespace sparse {
	int m[LOG+1][MAX], n;

	void build(int n2, int* v) {
		n = n2;
		for (int i = 0; i < n; i++) m[0][i] = v[i];
		for (int j = 1; (1<<j) <= n; j++) for (int i = 0; i+(1<<j) <= n; i++)
			m[j][i] = gcd(m[j-1][i], m[j-1][i+(1<<(j-1))]);
	}
	int query(int a, int b) {
		int j = __lg(b - a + 1);
		return gcd(m[j][a], m[j][b-(1<<j)+1]);
	}
}

signed main(){
    fastio;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sparse::build(n, a);

    int q;
    cin >> q;
    vector<int> queries(q);
    for (auto &u : queries) cin >> u;
    map<int,ll> ans;

    for (int i = 0; i < n; i++){
        int j = i;
        while (j < n){
            int g = sparse::query(i,j);
            int l = j, r = n-1;
            int end = j;
            while (l <= r){
                int mid = (l + r) / 2;
                if (sparse::query(i,mid) == g){
                    end = mid;
                    l = mid + 1;
                }
                else r = mid - 1;
            }
            ans[g] += end - j + 1;
            j = end + 1;
        }
    }
    for (auto u : queries) cout << ans[u] << endl;
}
