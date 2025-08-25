#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
const int MAX = 2e5+7;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f3f3f3f3fLL;


map<int, string> mp;
signed main(){
    winton;
    
    mp[0] = "Rafael"; 
    mp[1] = "Leonardo"; 
    mp[2] = "Donatello"; 
    mp[3] = "Michelangelo"; 
    int n, a[4];
    int sum = 0;
    for (int i = 0; i < 4; i++){
        cin >> a[i];
        sum += a[i];
    }
    cin >> n;
    vector<string> ans;
    for (int i = 0; i < 4; i++){
        if (a[i]+n > sum-a[i]) ans.push_back(mp[i]);
    }

    if (ans.empty()){
        cout << "sem vencedores" << endl;
    }
    else {
        sort(all(ans));
        for (auto u : ans) cout << u << endl;
    }

}