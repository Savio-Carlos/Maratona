#include <bits/stdc++.h>
#include <strings.h>
using namespace std;

#define endl '\n'
#define all(x) x.begin(), x.end()
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define debug(x) cout << #x << " = " << x << "\n";

signed main(){
    winton;
    int n;
    cin >> n;
    int val = 0;
    for (int i = 0; i < (1<<n); i++){
        int lsb = ((i) & ~(i-1));
        val ^= lsb; 
        for (int j = n-1; j >= 0; j--){
            if ((val >> j) & 1) cout << 1;
            else cout << 0;
        }
        cout << endl;
    }
}