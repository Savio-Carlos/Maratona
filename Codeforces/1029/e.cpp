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
    vector<int> a(n+4, -1), b(n+4,-1);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    if (a[n-1] == b[n-1]) {
        cout << n << endl;
        return;
    }   
    int maxdir = -1;
    set<int> seen;
    for(int i = n-2; i >= 0; i--){
        if (a[i] == b[i]) maxdir = max(maxdir, i);
        if (a[i] == a[i+1]) maxdir = max(maxdir, i);
        if (b[i] == b[i+1]) maxdir = max(maxdir, i);
        if (seen.count(a[i]))maxdir = max(maxdir, i);
        if (seen.count(b[i]))maxdir = max(maxdir, i);

        seen.insert(a[i+1]);
        seen.insert(b[i+1]);
    }
    cout << maxdir+1 << endl;
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--) solve();
}
