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
const int INF = LLONG_MAX;

void solve(){
    string s;
    cin >> s;
    string t = s;
    sort(all(t));
    bool difit = false, letter = false;
    for (char &u : s){
        if (isdigit(u)) difit = true;
        if (islower(u)) letter = true;
    }
    if (s == t && s.size() > 10 && letter && difit) cout << "S\n";
    else cout << "N\n";
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--)solve();
}