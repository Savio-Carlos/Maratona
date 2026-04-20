#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int long long
#define ld long double
#define endl '\n'

#define winton ios_base::sync_with_stdio(false),cin.tie(0)

signed main(){
    winton;
    int n;
    cin >> n;
    vector<pair<string,string>> a;
    for (int i = 0; i < n; i++){
        string s, t;
        cin >> s >> t;
        a.push_back({t,s});
    }
    sort(all(a));
    for (auto [t,s] : a) cout << s << " " << t << endl;
}

