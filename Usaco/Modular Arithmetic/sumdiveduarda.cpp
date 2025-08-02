#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MOD = 1e9+7;

int fastexpo(int a, int b){
    int res = 1;
    a%=MOD;
    while(b >= 1){
        if(b&1) res = (res*a)%MOD;
        a = (a*a)%MOD;
        b >>= 1;
    }
    return res;
}

signed main(){
	fastio;
    ifstream cin("sumdiv.in");
    ofstream cout("sumdiv.out");
	int a, b; cin >> a >> b;
    if(b == 0){
        cout << 1 << endl;
        return 0;
    }else{
        //(div^(b*(p+1))-1)/(div - 1)
        int ans = 1;
        for(int div = 2; div* div <= a; div++){
            if(!(a%div)){
                int exp = 0;
                while(!(a%div)){
                    a/=div;
                    exp++;
                }

                //b*(p+1)
                int pot = ( (exp * (b % (MOD-1))) % (MOD-1) + 1 ) % (MOD-1);
                int num = fastexpo(div, (pot))-1;
                if(num < 0) num += MOD;
                int den = (fastexpo(div-1, MOD-2));
                int prod = (num%MOD*den%MOD);
                ans = (ans * prod)%MOD;    
            }
        }

        if(a > 1){
            //(div^(b*(p+1))-1)/(div - 1)
            int div = a;
            int pot = ((b%(MOD-1))%(MOD-1) + 1)%(MOD-1);
            int num = fastexpo(div, (pot)) - 1;
            if(num < 0) num += MOD;
            int den = fastexpo(div-1, MOD-2);
            int prod = (num%MOD*den%MOD);
            ans = (ans * prod)%MOD;
        }

        cout << ans << endl;
    }
}