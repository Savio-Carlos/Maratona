#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll gcd(ll a, ll b){
    if (b==0) return a;
    return gcd(b, a%b);
}

int main() {
    ll t, a, b;
    cin >> t;
    
    while (t--){
        cin >> a >> b;
        cout << gcd(a,b) << endl;
    }
}