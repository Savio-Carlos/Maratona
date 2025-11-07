#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

const int MOD = 1e9+7;

int fastexpo(int a, int b){
    int res = 1;
    while(b > 0){
        if(b&1) res = (res*a)%MOD;
        a = (a*a)%MOD;
        b /= 2;
    }
    return res;
}

signed main(){
    fastio;
    int n1; cin >> n1;
    int n = n1%MOD;
    int sumi = (n*(n+1))%MOD;
    int sumisquare = ((((2*n)%MOD + 1)%MOD)*(sumi))%MOD;
    int inv2 = fastexpo(2, MOD-2);
    int inv6 = fastexpo(6, MOD-2);

    sumi = (((sumi*inv2)%MOD)*4)%MOD;
    sumisquare = (((sumisquare*inv6)%MOD)*4)%MOD;
    int ans = ((sumi + sumisquare)%MOD + n)%MOD;
    cout << ans << endl;
    
}