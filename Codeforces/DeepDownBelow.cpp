#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long
const int MAXL = 1e9+7;

signed main() {_
    int t; cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>> caves(n);
        vector<pair<int,int>> sorter;
        for (int i = 0; i < n; i++){
            int x; cin >> x;
            int highestDiff = 0, last = 0;
            for (int j = 0; j < x; j++){
                int m; cin >> m;
                caves[i].push_back(m);
                m-=j;
                highestDiff = max(highestDiff, m);
                
            }
            sorter.push_back({highestDiff,i});
        }
        sort(all(sorter));

        int l = 0, r = LLONG_MAX, ans;
        while(l <= r){
            int mid = l + ((r-l)/2);
            bool possible = true;
            int power = mid;
            for(auto &[sum,idx] : sorter){
                for (auto &i : caves[idx]){
                    if (power > i){
                        power++;
                    }
                    else {
                        possible = false;
                    }
                }
            }
            if (possible){
                r = mid - 1;
                ans = mid;
            }
            else {
                l = mid + 1;
            }
        }
        cout << ans << endl;
    }
}