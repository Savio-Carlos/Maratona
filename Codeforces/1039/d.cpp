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
/*
como max(ai,ai+1) > ai+2 eu sei que numa subsequencia de tamanho 3 eu sempre tenho uma LDS de no minimo 2
numa subs de tamanho 5 eu tenho uma LDS de no min 3
sempre somo n na resposta

*/

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    bool ans = true;
    for (auto &u : a) cin >> u;

    int mn = a[0];
    for (int i = 1; i < n; i++){
        if (a[i] - mn >= mn) ans = false; 
        mn = min(mn,a[i]);
    }
    if (ans) cout << "YES" << endl;
    else cout << "NO" << endl;

}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--)solve();
}
