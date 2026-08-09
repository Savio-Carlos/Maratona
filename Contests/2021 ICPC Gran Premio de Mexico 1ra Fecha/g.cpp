#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define ld long double
#define winton ios_base::sync_with_stdio(0),cin.tie(0)
#define all(x) x.begin(),x.end()
#define debug(x) cerr << #x << ": " << x << endl;

signed main(){
    winton;
    int n, m;
    cin >> n >> m;

    bool win = false;
    for (int i = m + 1; i <= n; ){
        while (__builtin_popcount(i)&1) i++;
        if (i >= n){
            win = (i == n); 
            break; 
        }
        i += m + 1;
    }
    if (win) cout << "Free snacks!" << endl;
    else cout << "Pay the bill" << endl;
}
