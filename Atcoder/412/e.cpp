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
const int MAX = 1e7+7;

bool visited[MAX];

vector<char> segmentedSieve(long long L, long long R) {
    // generate all primes up to sqrt(R)
    long long lim = sqrt(R);
    vector<char> mark(lim + 1, false);
    vector<long long> primes;

    for (long long i = 2; i <= lim; ++i) {
        if (!mark[i]) {
            primes.emplace_back(i);
            for (long long j = i * i; j <= lim; j += i)
                mark[j] = true;
        }
    }

    vector<char> isPrime(R - L + 1, true);
    for (long long i : primes){
        for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i){       
            isPrime[j - L] = false;
        }
    }
    if (L == 1) isPrime[0] = false;
    
    //para pegar os primos basta fazer i + L no vetor de isprime 
    return isPrime;
}

vector<int> sieve(int n) {
    vector<int> primes;
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = false;
    is_prime[1] = false;
    for (int p = 2; p * p <= n; ++p) {
        if (is_prime[p]) {
            for (int multiple = p * p; multiple <= n; multiple += p) {
                is_prime[multiple] = false;
            }
        }
    }
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

signed main(){
    winton;
    int l, r;
    cin >> l >> r;
    int ans = 1;

    vector<char> primeslr = segmentedSieve(l+1,r);
        for (int i = 0; i < (int)primeslr.size(); i++){
        if (primeslr[i]) ans++;
    }
    //debug(ans);

    vector<int> primes = sieve(sqrt(r));
    for (auto p : primes){
        if (visited[p]) continue;

        visited[p] = true;
        int x = p;
        while (x * p <= r){
            if (x*p > l) ans++;
            x*=p;
        }
    }

    cout << ans << endl;
}