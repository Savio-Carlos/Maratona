#include <bits/stdc++.h>
#define int long long
#define ld long double
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;


signed main(){
    fastio;
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &u : a) cin >> u;
    a.push_back(0);
    if (n == 1){
        cout << 1 << endl;
        return 0;
    }
    int ans = 0;
    int i = 0;
    while (i < n){
        int cur = (a[i+1] - a[i]);
        int j = i+2;
        while(j < n){
        if ((a[j] - a[j-1]) == cur) j++;
        else break;
        }
        ans++;
        i = j;
    }
    cout << ans << endl;
}