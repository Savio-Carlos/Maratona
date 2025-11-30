#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

signed main(){
    fastio;
    int n; cin >> n;
    map<string, int> mp;
    vector<string> nomes{ "Abigail", "Sebastian", "Penny", "Sam", "Leah", "Harvey", "Haley",
"Maru", "Alex", "Emily" };
    for(int i=0;i<n;i++){
        string s;
        int x;
        cin >> s >> x;
        mp[s] += x;
    }

    for(int i=0;i<nomes.size();i++){
        if(mp[nomes[i]] >= 250){
            cout << nomes[i] << " " << min(8LL, mp[nomes[i]] / 250) << endl;
        }
    }

    // for(auto [s, x]: mp){
    //     if(x >= 250) cout << s << " " << x / 250 << endl;
    // }
    return 0;
}