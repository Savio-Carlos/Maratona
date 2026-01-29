#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)

void solve(){
    int n;
    cin >> n;
    vector<int> a(n+1);
    priority_queue<tuple<int,int,int>> pq;
    pq.push({n, -1, n});
    int cur = 1;
    while (!pq.empty()) {
        auto [len, ml, r] = pq.top();
        pq.pop();
        int l = -ml;
        int mid = (len & 1) ? (l + r) / 2 : (l + r - 1) / 2;
        a[mid] = cur++;
        if (mid - 1 >= l) pq.push({mid - l, -l, mid - 1});
        if (r >= mid + 1) pq.push({r - mid, -(mid + 1), r});
    }
    for (int i = 1; i <= n; i++) cout << a[i] << " ";
    cout << endl;
}

signed main() {
    winton;
    int t;
    cin >> t;
    while(t--) solve();
}