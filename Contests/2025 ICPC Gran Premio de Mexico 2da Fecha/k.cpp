#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fastio ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)



signed main(){
    fastio;
    int n, k; cin >> n >> k;
    vector<int> l(n), r(n);
    for(int i = 0; i < n; i++) cin >> l[i];
    for(int i = 0; i < n; i++) cin >> r[i];
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());

    int ans = 0;
    for(int i = 0; i < n; i++){
        int sum = (l[i] + r[i]);
        if(sum > k) break;
        else k-=sum;
        ans++;
    }
    cout << ans << endl;
}