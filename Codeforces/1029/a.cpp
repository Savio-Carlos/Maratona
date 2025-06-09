#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAX = 2e5+7;
const int INF = INT_MAX;

void solve(){
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    int first, last;
    for (int i = 0; i < n; i++){
        cin>>a[i];
        if (a[i]) last = i;
    }
    for (int i = 0; i < n; i++){
        if (a[i]){
            first = i;
            break;
        }    
    }
    if (last - first + 1 <= x) cout << "YES" << endl;
    else cout << "NO" << endl;
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--) solve();
}