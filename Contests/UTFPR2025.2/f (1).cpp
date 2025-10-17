#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'

signed main() {
    fastio;
    int n, m; cin >> n >> m;
    //mask, qtd
    map<int, int> mp;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        int mask = 0;
        for(int j = 0; j < m; j++){
            if(s[j] == 'S') mask |= (1<<j);
        }
        mp[mask]++;
    }
    int tot = (1<<m)-1;
    int ans = 0;
    for(int i = 0; i < (1<<m); i++){
        for(int j = 0; j < (1<<m); j++){
            if(i == j){
                if(i != tot) continue;
                else{
                    ans += (mp[i]*mp[i]-1)/2;
                }
            }
            if((i | j) == tot){
                ans += (mp[i]*mp[j]);
            }
        }
    }
    cout << ans/2 << endl;
}