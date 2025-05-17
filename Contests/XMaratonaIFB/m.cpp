#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MOD = 1e9+7;

int fastexpo(int a, int b){
    int res = 1;
    while(b > 0){
        if(b&1) res = (res*a)%MOD;
        a = (a*a)%MOD;
        b/=2;
    }
    return res;
}

signed main(){
    fastio;
    int n; cin >> n;
    cout << (fastexpo(2, n+1) - 3)%MOD << endl;
}