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
const int MAX = 1e6+7;
const int MOD = 1e9+7;
const int INF = LLONG_MAX;

/*
pegar todos os coprimos de n
como gcd vai acumulando, eu so quero pegar os caras que gcd(i,n) == 1
no final o gcd ou vai ser n-1 ou 1
se for n-1 eu apenas removo o ultimo elemento
ver precisamente pq isso funciona 
*/

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

signed main() {
    winton;
    int n; 
    cin >> n;
    vector<int> ans;
    int cur = 1;
    for (int i = 1; i < n; i++){
        if (gcd(n,i) == 1){
            cur*=i;
            cur%=n;
            // debug(i);
            // debug(cur);
            // debug(cur%n);
            ans.push_back(i);
        } 
    }
    if (cur%n != 1) ans.erase(ans.end()-1);
    cout << ans.size() << endl;
    for (auto u : ans) cout << u << " ";
}