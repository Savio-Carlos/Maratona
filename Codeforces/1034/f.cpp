#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
const int MAX = 1e5+7;
const int MOD = 1e9+7;
const int INF = LLONG_MAX;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

vector<bool> is_prime(MAX + 1, true);
vector<int> primes;
void sieve() {
    is_prime[0] = false;
    is_prime[1] = false;
    for (int p = 2; p * p <= MAX; ++p) {
        if (is_prime[p]) {
            for (int multiple = p * p; multiple <= MAX; multiple += p) {
                is_prime[multiple] = false;
            }
        }
    }
    for (int i = 2; i <= MAX; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
}

void solve(){
    int n; 
    cin >> n;
    vector<int> ans(n+1);
    for (int i = 1; i <= n; i++) ans[i] = i;
    for (int i = primes.size()-1; i >= 0; i--){
        int p = primes[i];
        int q = p;
        for (int j = p; j <= n; j+= p){
            if (ans[j] != j) continue;
            ans[j] = ans[q];
            ans[q] = j;
            q = j;
        }
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
}

signed main(){
    winton;
    sieve();
    int t;
    cin >> t;
    while(t--)solve();
}