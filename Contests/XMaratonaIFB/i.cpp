#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)

signed main(){
    fastio;
    int n; cin >> n;
    if(n == 3 || n == 2){
        cout << "NO SOLUTION\n";
        return 0;
    }else if(n == 1) cout << 1 << endl;
    else if(n == 4) cout << "2 4 1 3" << endl;
    else {
        for(int i = 1; i <= n; i+=2){
            cout << i << " ";
        }
        for(int i = 2; i <= n; i+=2) cout << i << " ";
        cout << endl;
        return 0;
    }
}