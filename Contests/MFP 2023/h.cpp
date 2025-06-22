#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define debug(x) cout << #x << " = " << x << "\n";
const int MAX = 5e5+7;
const int INF = LLONG_MAX;

int n;

signed main(){
    winton;
    cin >> n;
    vector<int> a(n), sums(n-1);
    unordered_map<int,int> mp;
    mp.reserve(2*n);
    for (int &u : a) {
        cin >> u;
        mp[u]++;
    }
    for (int &u : sums) cin >> u;

    for (auto u : mp){
        int diff = sums[0] - u.first;
        if (mp.find(diff) != mp.end()){
            vector<int> ans(n);
            ans[0] = u.first;
            ans[1] = diff;
            u.second--;
            mp[diff]--;
            int PARAR;
            bool pos = true;
            for (int i = 2; i < n; i++){
                int diff = sums[i - 1] - ans[i - 1];
                if (mp.count(diff) && mp[diff] > 0){
                    ans[i] = diff;
                    mp[diff]--;
                }
                else {
                    pos = false;
                    PARAR = i;
                    break;
                }
            }
            if (pos) {
                for (int i = 0; i < n; i++) {
                    cout << ans[i] << " ";
                }
                cout << endl;
                return 0;
            } 
            else {
                mp[sums[0] - u.first]++;
                u.second++;
                for (int i = 2; i < PARAR; i++) {
                    mp[ans[i]]++;
                }
            }
            
        }
    }
}