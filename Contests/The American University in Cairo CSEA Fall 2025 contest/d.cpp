#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0), cout.tie(0)
#define int long long
#define endl '\n'

const int MAXN = 150;
int primo[MAXN];
vector<int> primes;

void sieve(){
    for(int i = 2; i < MAXN; i++) primo[i] = i;

    for(int i = 2; i < MAXN; i++){
        if(primo[i] == i){
            primes.push_back(i);
            for(int j = i*i; j < MAXN; j += i) primo[j] = i;
        }
    }
}

void solve(){
    int a, b; cin >> a >> b;
        if (a == 0 || b == 0) {
        cout << -1 << endl;;
        return;
    }
    for(auto u : primes){
        if(a%u != 0 && b%u != 0){
            cout << u << endl;
            return;
        }
    }
}

signed main(){
    fastio;
    int t; cin >> t;
    sieve();
    while(t--){
        solve();
    }
}