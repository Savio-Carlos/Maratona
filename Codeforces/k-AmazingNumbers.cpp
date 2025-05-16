#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)

signed main () {
    winton;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n), diff(n+1,-1);
        map<int,int> mp;
        map<int,pair<int,int>> dist;
        for (int i = 0; i < n; i++){
            cin >> a[i];
            if (dist.find(a[i]) == dist.end()){
                dist[a[i]].first = i+1;
                dist[a[i]].second = n-i;
            }
            else dist[a[i]].second = n-i;
        }
        for (int i = 0; i < n; i++){
            if (diff[a[i]] > 0){
                diff[a[i]] = max(diff[a[i]], i - mp[a[i]]);
            }
            else {
                diff[a[i]] = max(dist[a[i]].second, dist[a[i]].first);
               // cout << dist[a[i]].first << " " << dist[a[i]].second << endl;
            }
            mp[a[i]] = i;
        }
        vector<int> ans(n+1, -1);

        for (int i = 1; i <= n; i++){
            if (diff[i] != -1 && diff[i] <= n){
                if (ans[diff[i]] == -1){
                    ans[diff[i]] = i;
                }
                else {
                    ans[diff[i]] = min(ans[diff[i]], i);
                }
            }
        }
        for (int i = 1; i <= n; i++){
            if (ans[i] == -1){
                ans[i] = ans[i-1];
            }
            else if (ans[i-1] != -1){
                ans[i] = min(ans[i], ans[i-1]);
            }
        }
        //for (auto y : diff) cout << y << " ";
        //cout << endl;

        for (int i = 1; i <= n; i++){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}