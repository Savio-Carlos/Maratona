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

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    multiset<int> modsb;
    for (auto &u : a) cin >> u;
    for (auto &u : b){
        cin >> u;
        modsb.insert(u%k);
    } 
    for (int i = 0; i < n; i++){
        //debug(abs((a[i] % -k + -k) % -k));
        if (modsb.find(a[i]%k) == modsb.end() && modsb.find(abs((a[i] % -k + -k) % -k)) == modsb.end()){
            cout << "NO" << endl;
            return;
        }
        if(modsb.find(a[i]%k) != modsb.end()) modsb.erase(modsb.find(a[i]%k));
        else if(modsb.find(abs((a[i] % -k + -k) % -k)) != modsb.end()) modsb.erase(modsb.find(abs((a[i] % -k + -k) % -k)));
    }
    cout << "YES" << endl;
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--)solve();
}
