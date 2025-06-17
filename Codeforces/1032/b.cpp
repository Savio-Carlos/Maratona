#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define debug(x) cout << #x << " = " << x << "\n";
const int MAX = 2e5+7;
const int INF = INT_MAX;

void solve(){
    int n;
    string s;
    cin >> n >> s;
    map<char,int> mp;
    bool ans = false;
    for(int i = 0; i < n; i++){
        if(mp.count(s[i]) > 0 && i < n-1) ans = true;
        mp[s[i]]++;
    }

    map<char,int> mp2;
        for(int i = n-1; i >= 0; i--){
        if(mp2.count(s[i]) > 0 && i > 0) ans = true;
        mp2[s[i]]++;
    }
    if(ans)cout << "Yes" << endl;
    else cout << "No" << endl;
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--) solve();
}