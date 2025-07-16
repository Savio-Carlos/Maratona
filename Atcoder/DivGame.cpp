#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
const int MAX = 2e5+7;
const int MOD = 1e9+7;
const int INF = LLONG_MAX;

int n;

vector<int> factorize(int x){
    vector<int> primes;
    int p = x;
    for (p = 2; p*p <= n; p++){
        while(x%p == 0){
            x/=p;
            primes.push_back(p);
        } 
    }
    if (x > 1)primes.push_back(p);
    return primes;
}

signed main(){
    winton;
    cin >> n;
    vector<int> factors = factorize(n);
    map<int,int> cnt;
    int ans = 0;
    for (auto u : factors) cnt[u]++;
    for (auto &[u,c] : cnt){
        int i = 1;
        while (c - i >= 0){
            c -= i;
            i++;
            ans++;
        }
    }
    cout << ans << endl;
}