#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

signed main(){
    fastio;
    int n; cin >> n;
    map<string, int> mp;
    for(int i = 0;i < n; i++){
        string s; cin >> s;
        mp[s]++;
    }
    int mx = 0;
    string win;
    for(auto [u, cnt]: mp){
        if(cnt > mx){
            mx = cnt;
            win = u;
        }
    }
    cout << win << endl;
}