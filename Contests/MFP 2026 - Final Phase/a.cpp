#include <bits/stdc++.h>
using namespace std;

#define endl '\n' 
#define winton ios_base::sync_with_stdio(0),cin.tie(0)

signed main(){
    winton;
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++){
        int x;
        char c;
        cin >> c >> x;
        if (c == '-') x *= -1;
        ans += x;
    }    
    cout << ans << endl;
}
