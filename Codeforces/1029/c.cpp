#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAX = 2e5+7;
const int INF = INT_MAX;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a) cin >> i;

    set<int> base;
    base.insert(a[0]);
    
    int ans = 1;
    set<int> cur;
    for (int i = 1; i < n; i++){
        cur.insert(a[i]);
        base.insert(a[i]);
        if (cur == base){
            ans++;
            cur.clear();
        }
    }

    cout << ans << endl;
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--) solve();
}