#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAX = 1e6+7;

int n, spf[MAX], cnt[MAX];
vector<int> prime;

void build(){
    for (int i = 2; i < MAX; i+=2) spf[i] = 2;
    for (int i = 3; i < MAX; i+=2){
        if (spf[i] == 0){
            spf[i] = i;
            for (int j = i; j*i <= MAX; j+=2){
                if (spf[i*j] == 0) spf[i*j] = i;
            }
        }
    }
}
vector<int> factorize(int x){
    vector<int> primes;
    while (x > 1){
        int p = spf[x];
        primes.push_back(p);
        while(x%p == 0) x/=p;
    }
    return primes;
}

void factor (int n){
    for (int i = 2; i < sqrt(n); i++){
        if (n%i == 0)prime.push_back(i);
        while(n%i == 0){
        n = n/i;
        }
    }
    if (n > 1) prime.push_back(n);
}

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

signed main(){
    int y, k;
    cin >> y >> k;
    
}