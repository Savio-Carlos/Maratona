#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MAXN = 1e3+1;
bool primos[MAXN];

bool soma(int n){
    if(n < 2) return false;
    if(n == 2) return true;
    if(n%2 == 0) return false;
    for(int i = 2; i*i <= n; i++){
        if (n % i == 0) return false;
    }
    return true; 
}

void sieve(){
    for(int i = 0; i < MAXN; i++) primos[i] = true;

    primos[0] = false;
    primos[1] = false; 
    for(int i = 2; i*i < MAXN; i++){
        if(primos[i] == true){
            for(int j = i*i; j < MAXN; j+=i){
                primos[j] = false;
            }
        }
    }
}

signed main() {
    fastio;
    sieve();
    int n; cin >> n;
    vector<int> somas(n, 0);
    vector<int> ans;
    for(int i = 0; i < n; i++){
        int m, x; cin >> m >> x;
        for(int j = 2; j <= m; j++){
            cin >> x;
            if(primos[j] == true) somas[i] += x;
        }
        if(soma(somas[i])) ans.push_back(somas[i]);
    }

    if(ans.empty()){
        cout << "ITS OVER SOBROU NADA PRO BETINHA\n";
        return 0;
    }
    cout << ans.size() << endl;
    for(auto u : ans) cout << u << " ";
    cout << endl;
} 