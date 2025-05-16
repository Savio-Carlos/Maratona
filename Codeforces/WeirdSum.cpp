#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long
#define vi vector<int>
#define pb push_back
const int MAXL = 1e9+7;

signed main(){_
    int n, m; cin >> n >> m;
    int grid[n][m];
    map <int, pair<vector<int>, vector<int>>> mp;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> grid[i][j];
            mp[grid[i][j]].first.pb(i+1);
            mp[grid[i][j]].second.pb(j+1);
        }
    }
    int ans = 0;
    for (auto x : mp){
        sort(all(x.second.first));
        sort(all(x.second.second)); 
        int sum1 = 0;
        int sum2 = 0;
        int k = x.second.first.size();
        for (int i = 0; i < k; i++){
            int r = x.second.first[i];
            int c = x.second.second[i];
            sum1 += (2*i+1-k) * r;
            sum2 += (2*i+1-k) * c;
        }
        ans += sum1 + sum2;
    }
    cout << ans << endl;

}