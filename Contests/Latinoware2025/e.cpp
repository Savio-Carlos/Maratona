#include <bits/stdc++.h>
#define int long long
#define ld long double
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

signed main(){
    int n, m; cin >> n >> m;
    vector<int> pref(n+1, 0);
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        pref[i] = x + pref[i-1];
    }

    map<int, int> mp;
    int cur = 0;
    for(int i = 1; i <= n; i++){
        cur += i;
        mp[cur] = i;
    }

    while(m--){
        int l, r; cin >> l >> r;
        int val = pref[r] - pref[l-1];
        //cout << r - l + 1 << endl;
        if(mp[val] != 0 && mp[val] == (r - l + 1)){
            cout << "Bom\n";
        }
        else cout << "Ruim\n";
    }
}