#include <bits/stdc++.h>
using namespace std;

#define int long long
#define winton ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

const int MAX = 1e6+7;

vector<bool> is_prime(MAX + 1, true);

void sieve() {
    is_prime[0] = false;
    is_prime[1] = false;
    for (int p = 2; p * p <= MAX; ++p) {
        if (is_prime[p]) {
            for (int i = p * p; i <= MAX; i += p) {
                is_prime[i] = false;
            }
        }
    }
}

signed main(){
    winton;
    sieve();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        int sq = sqrt(x);
        if (sq*sq != x) cout << "NO" << endl;
        else if (is_prime[sq]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}