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
const int MAX = 2e5+7;
const int MOD = 1e9+7;
const int INF = LLONG_MAX;

struct casino{
    int l, r, real;
    bool operator<(const casino &A) { return l < A.l; }
};

void solve(){
	int n, k; 
    cin >> n >> k;
    vector<casino> a(n);
    for (auto &[l,r,real] : a) cin >> l >> r >> real;
    sort(all(a));
    priority_queue<int> pq;
    int idx = 0;
    int coins = k;
    while(1){
        while(idx < n && a[idx].l <= coins){
            pq.push(a[idx].real);
            idx++;
        }
        while(!pq.empty() && pq.top() <= coins){
            pq.pop();
        }
        if(pq.empty()) break;
        coins = pq.top();
        pq.pop();
        //debug(coins);
    }
    cout << coins << endl; 
}

signed main(){
	winton;
	int t; cin >> t;
	while(t--){
		solve();
	}
}