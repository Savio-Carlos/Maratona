#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

signed main() {
    fastio;
    int n, q; cin >> n >> q;
    vector<string> v;
    map<string, int> mp, freq, punished;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        v.push_back(s);
        int tot; cin >> tot;
        mp[s] = tot;
    }

    int cnt = 0;
    while(q--){
        string s;
        int tot; cin >> s >> tot;
        if(mp[s] == 0) continue;
        if(freq[s] >= 3) continue;
        if(tot > mp[s]){
            freq[s]++;
            continue;
        }else if(!punished[s]){
            cnt++;
            punished[s] = 1;
        }
    }
    if(cnt == 0){
        cout << -1 << endl;
        return 0;
    }
    cout << cnt << endl;
    for(int i = 0; i < n; i++){
        if(punished[v[i]] == 1) cout << v[i] << endl;
    }

}