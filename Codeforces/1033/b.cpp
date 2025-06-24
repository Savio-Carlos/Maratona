#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define debug(x) cout << #x << " = " << x << "\n";
const int MAX = 5e5+7;
const int INF = LLONG_MAX;

void solve(){
    int n, s;
    cin >> n >> s;
    vector<tuple<int,int,int,int>> balls(n);
    int xis = 0;
    for (auto &[dx,dy,xi,yi] : balls){
        cin >> dx >> dy >> xi >> yi;
        if (xi == yi){
            if (dx == dy && (dx == 1 || dx == -1))xis++;
        } 
        if (xi + yi == s){
            if (dx + dy == 0) xis++;
        }
    } 
    cout << xis << endl;
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--) solve();
}