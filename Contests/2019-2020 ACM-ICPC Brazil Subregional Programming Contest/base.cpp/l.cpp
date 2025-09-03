#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'

const int MAXN = 1e5+7;

ll fastexpo (ll base, ll exp){
    ll res = 1;
    while(exp){
        if (exp & 1) res = res * base;
        exp >>= 1;
        base = base * base;
    }
    return res;
}

signed main(){
    fastio;
    ll n;
    cin >> n;
    ll qtd = __builtin_popcountll(n);
    ll ans = fastexpo(2LL, qtd);
    cout << ans;
}