#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld double
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

signed main(){
    fastio;
    int n;
    cin >> n;
    map<int,int> mp;

    double total = 0;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        total += stod(s) * 100;
        int val = (s[s.size()-1] - '0') % 5;
        mp[val]++;
        cout << val << endl;
    }
    total *= 100;
    int dois = min(mp[4], mp[3]);
    int ans = dois * 2;
    mp[4] -= dois;
    ans += mp[4] / 3;
    mp[3] -= dois;
    ans += mp[3] / 2;
    ans += mp[1];
    ans += 2 * mp[2];
    
    cout << total << endl;
    cout << (total - ans) << endl;
}