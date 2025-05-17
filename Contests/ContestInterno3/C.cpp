#include <bits/stdc++.h>
using namespace std;
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long
#define ld long double
const int MOD = 1e9+7;

vector<int> prime;

void factor (int n){
    for (int i = 2; i <= sqrt(n); i++){
        if (n%i == 0)prime.push_back(i);
        while(n%i == 0){
        n = n/i;
        }
    }
    if (n > 1) prime.push_back(n);
}

signed main() {
    winton;
    int n;
    cin >> n;
    factor(n);
    //for (auto u : prime) cout << u << " ";
    cout << endl;
    if (n%2 == 0){
        cout << n/2;
    }
    else if (n/prime[0] != 1){
        cout << (n-prime[0])/2 + 1 << endl;
    }
    else cout << "1" << endl;
}