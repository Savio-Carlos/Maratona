#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'

int main() {
    fastio;
    int n, m; cin >> n >> m;
    //mask, qtd
    vector<int> mp(1 << m, 0);  
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        int mask = 0;
        for(int j = 0; j < m; j++){
            if(s[j] == 'S') mask |= (1<<j);
        }
        mp[mask]++;
    }
    int tot = (1<<m)-1;
    long long ans = 0;
    for(int i = 0; i < (1<<m); i++){
        if(mp[i] == 0) continue;
        for(int j = i; j < (1<<m); j++){
            if(mp[j] == 0) continue;
            if((i | j) == tot){
                if(i == j) ans += (mp[i]*(mp[i]-1))/2;
                else ans += (mp[i]*mp[j]);
            }
        }
    }
    cout << ans << endl;
}