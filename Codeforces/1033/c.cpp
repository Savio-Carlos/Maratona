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
    int n, m;
    cin >> n >> m;
    int minisum = n; //cadeia de ums
    int maxsum = (n*(n+1))/2; //PA
    if (m < minisum || m > maxsum){
        cout << "-1" << endl;
        return;
    }
    int root = -1;
    for (int i = 1; i <= n; i++){
        if (i + n-1 == m){
            root = i;
            break;
        }
    }
    debug(root);
    // if (root != -1){
    //     cout << root << endl;
    //     int prev = root;
    //     for (int i = 1; i <= n; i++){
    //         if (i == root) continue;
    //         cout << prev << " " << i << endl;
    //         prev = i;
    //     }
    //     return;
    // }
    for (int i = 1; i <= n; i++){
        if (i*n-1 + ((i*(i+1))/2 - i) == m){
            root = i;
            break;
        }
        cout << i*n-1 + (((i*(i+1))/2) - i) << endl;
    }
    debug(root);
    

    
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--) solve();
}