#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)

int cnt = 0;

void mergeSwap(vector<int>& a, int l, int r) {
    if (r - l <= 1) return;
    
    int mid = (l + r) / 2;
    mergeSwap(a, l, mid);
    mergeSwap(a, mid, r);
    if (a[mid] < a[l]) {
        for (int i = 0; i < (mid - l); i++) {
            swap(a[l + i], a[mid + i]);
        }
        cnt++;
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &u : a) cin >> u;
    cnt = 0;
    mergeSwap(a, 0, n);
    for (int i = 0; i < n; i++) {
        if (a[i] != i+1){
            cout << -1 << endl;
            return;
        }
    }
    cout << cnt << endl;
}

signed main() {
    winton;
    int t;
    cin >> t;
    while(t--) solve();
}
