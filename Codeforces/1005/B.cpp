#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
using namespace std;
#define endl '\n'
#define int long long
const int MAXL = 1e5+7;

signed main() {_
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        set<int> unique;
        vector<int> arr(n), freq(n+1);
        for (int i = 0; i < n; i++){
            cin >> arr[i];
            unique.insert(arr[i]);
            freq[arr[i]]++;
        }

        pair<int,int> ans;
        int cur = 0;
        int bestl = 0;
        for (int l = 0; l < n; l++) {
            if (freq[arr[l]] > 1) continue;
            int r = l;
            while (r < n && freq[arr[r]] == 1) {
                r++;
            }
            cur = r-l;
            if (cur > bestl){
                bestl = cur;
                ans.first = l+1;
                ans.second = r;
            }
            l = r-1;
        }  
        if (n == 1) cout << "1 1" << endl;
        else if (unique.size() == 1 || ans.second == 0) cout << "0" << endl;
        else cout << ans.first << " " << ans.second << endl;
    }
}