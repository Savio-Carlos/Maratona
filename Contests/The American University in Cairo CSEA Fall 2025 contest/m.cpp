#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MOD = 1e9+7;

int fastexpo(int a, int b){
    int res = 1;
    while(b > 0){
        if(b&1) res = (a*res)%MOD;
        a = (a*a)%MOD;
        b >>=1;
    }
    return res;
}

signed main(){
    int n; cin >> n;
	string s; cin >> s;
    int cnt = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '0') cnt++;
    }

    int v = (fastexpo(2, cnt) + MOD - 1)%MOD;
    cout << v << endl;
}