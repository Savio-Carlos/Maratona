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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int ans = 0;
    for (int &i : a) cin >> i;
    sort(all(a));
    for (int i = 0; i <= 60; i++){
        for (int j = 0; j < n; j++){
            int cur = (1LL<<i);
            if (!(a[j] & cur) && k >= cur){
                k-=cur;
                a[j] |= cur;
            }  
        }
    }
    ans = 0;
    for (int &i : a)ans += __builtin_popcountll(i);
    cout << ans << endl;
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--) solve();
}