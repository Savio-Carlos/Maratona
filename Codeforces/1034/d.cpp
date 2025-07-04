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
const int MAX = 1e5+7;
const int MOD = 1e9+7;
const int INF = LLONG_MAX;

void solve(){
    int n, k, cnt1 = 0;
    cin >> n >> k;
    string s;
    cin >> s;
    for (auto u : s){
        int x = u - '0';
        if(x) cnt1++;
    } 
    if (cnt1 <= k || k > n/2) cout << "Alice\n";
    else cout << "Bob\n"; 
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--) solve();
}