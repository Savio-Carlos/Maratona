#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long
const int MAXL = 1e5+7;

signed main() {_
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector<char> arr(n);
        vector<int> pfx(n+1, 0);
        for (int i = 0; i < n; i++){
            cin >> arr[i];
            if (arr[i] == 'W')pfx[i+1]++;
            pfx[i+1] += pfx[i];
        }
        int r = k, ans = LLONG_MAX;
        for (int l = 0; r <= n; l++, r++){

            int cur = pfx[r] - pfx[l];
            ans = min(cur,ans);
        }
        cout << ans << endl;
    }
}

/*
        for (int u : pfx) cout << u << " ";
        cout << endl;
*/