#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)

signed main () {
    winton;
    int n;
    cin >> n;
    map<string,string> mp;
    map<string, int> cnt;
    for (int i = 0; i < n; i++){
        string s;
        int k;
        cin >> s >> k;
        cnt[s] = 0;
        for (int j = 0; j < k; j++){
            string p; cin >> p;
            mp[p] = s;
        }
    }
    int x; cin >> x;

    for(int i = 0; i < x; i++){
        string a;
        cin >> a;
        if (mp.count(a)) {
            cnt[mp[a]]++;
        }
    }
    int ans = 0;
    string resp;
    for (auto u : cnt){
        if (u.second > ans){
            ans = u.second;
            resp = u.first;
        }
    }
    cout << resp << endl;
}
