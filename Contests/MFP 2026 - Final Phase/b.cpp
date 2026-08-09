#include <bits/stdc++.h>
using namespace std;

#define endl '\n' 
#define winton ios_base::sync_with_stdio(0),cin.tie(0)
#define all(x) x.begin(), x.end()
#define int long long

#define debug(x) cerr<<#x<<": " << x << endl;
#define vdebug(x) cerr << #x << ": "; for(auto i : x) cerr << i << " "; cerr << endl;

const int INF = 1e18;

signed main(){
    winton;
    int n, q, k;
    cin >> n >> q >> k;
    while(q--){
        int l, r;
        cin >> l >> r;
        if (k >= l and k <= r){
            int add = n - r;
            k += add;
        }
        else if (k > r){
            int add = r - l + 1;
            k -= add;
        }
        else if (k < l){
            //nada
        }
    }
    cout << k << endl;
}
