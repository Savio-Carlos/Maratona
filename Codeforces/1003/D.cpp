#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
using namespace std;
#define endl '\n'
#define int long long
const int MAXL = 1e5+7;

signed main() {_
    int t; cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> arr(n, vector<int>(m));
        vector<pair<int,int>> scores(n);
        for (int i = 0; i < n; i++){
            int cur = 0;
            for (int j = 0; j < m; j++){
                cin >> arr[i][j];
                cur += arr[i][j];
            }
            scores[i] = {cur, i};
        } 

        sort(scores.begin(), scores.end(),greater<pair<int,int>>());
        int ans = 0;
        int temp = 0;
        for (auto [sc, idx] : scores){
            for (auto i : arr[idx]){
                temp += i;
                ans += temp;
            }
        }
        cout << ans << endl;
    }   
}