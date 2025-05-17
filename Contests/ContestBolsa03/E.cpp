#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)

vector<char> segmented_sieve(int l, int r){
    int lim = sqrt(r);
    vector<char> mark(lim+1, false);
    vector<int> primes;
    for (int i = 2; i <= lim; i++){
        if (!mark[i]){
            primes.emplace_back(i);
            for (int j = i*i; j < lim; j+=i){
                mark[j] = true;
            }
        }
    }

    vector<char> isPrime (r - l + 1, true);
    for (int i : primes){
        for (int j = max(i*i, (l + i -1) / i * i); j <= r; j += i){
            isPrime[j-l] = false;
        }
    }
    if (l == 1) isPrime[0] = false;
    return isPrime;
}

signed main () {
    winton;
    int t; 
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<char> ans = segmented_sieve(n,m);
        for (int i = n; i <= m; i++){
            if (ans[i-n]) cout << i << endl;
        }
        cout << endl;
    }
}