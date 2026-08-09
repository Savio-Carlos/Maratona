#include <bits/stdc++.h>
using namespace std;

#define endl '\n' 
#define winton ios_base::sync_with_stdio(0),cin.tie(0)
#define all(x) x.begin(), x.end()
#define int long long

#define debug(x) cerr<<#x<<": " << x << endl;
#define vdebug(x) cerr << #x << ": "; for(auto i : x) cerr << i << " "; cerr << endl;

const int MOD = 998244353;

int fastExpo(int b, int e){
    int r = 1;
    while(e){
        if (e&1) r = (r * b) % MOD;
        b = (b*b) % MOD; 
        e >>= 1;
    }
    return r;
}

int modiv(int a, int b){
    return (((a % MOD )* (fastExpo(b, MOD-2) % MOD)) % MOD);
}

int fatorial(int n){
    int r = 1;
    while(n){
        r = (r * n)%MOD;
        n--;
    } 
    return r;
}


signed main(){
    winton;
    int n, k;
    cin >> n >> k;
    int tot = fastExpo(k,n);
    int f = fatorial(k) * (k * (n-k) % MOD) % MOD;
    cout << modiv(f,tot) << endl;
    cout << modiv(60,81) << endl;

}


/*
aaaa
bbbb
cccc

aaab
aaac
*/