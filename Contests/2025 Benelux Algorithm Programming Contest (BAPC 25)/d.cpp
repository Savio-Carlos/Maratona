#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false),cout.tie(0),cin.tie(0) 

signed main(){
    fastio;
    int n;
    cin >> n;
    unordered_map<int, unordered_set<int>> mp;
    for (int i = 0; i < n; i++){
        int k;
        cin >> k;
        unordered_map<int, unordered_set<int>> local;
        for (int j = 0; j < k; j++){
            int x;
            cin >> x;
            for (auto u : mp[x]){
                if (u == i) continue;
                local[u].insert(x);
                if (local[u].size() > 1){
                    cout << *(local[u].begin()) << " " << *(prev(local[u].end())) << " " << i + 1 << " " << u+1 << endl;
                    return 0;
                }
            }
            mp[x].insert(i);
        }
    }
    cout << "impossible" << endl;

}