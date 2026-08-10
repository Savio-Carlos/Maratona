#include <bits/stdc++.h>
using namespace std;

#define endl '\n' 
#define winton ios_base::sync_with_stdio(0),cin.tie(0)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int long long
#define ld long double

#define debug(x) cerr<<#x<<": " << x << endl;
#define vdebug(x) cerr << #x << ": "; for(auto i : x) cerr << i << " "; cerr << endl;

const int MAX = 1e5+7;

signed main(){
    winton;
    int n;
    cin >> n;
    vector<int> pfx(MAX+1);
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        pfx[x]++;
    }
    for (int i = 1; i < MAX ; i++){
        pfx[i] += pfx[i-1];
    }

    int q;
    cin >> q;
    while(q--){
        int r;
        cin >> r;
        if (r >= MAX) cout << n << endl;
        else cout << pfx[r] << endl;
    }
}