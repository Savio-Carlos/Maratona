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
const int MAX = 2e5+7;
const int MOD = 1e9+7;
const int INF = INT_MAX;

int solve(int n){
    vector<int> divisors;
    for (int i = 1; i*i <= n; i++){
        if (n%i == 0){
            divisors.push_back(i);
            if (n/i != i)divisors.push_back(n/i);
        } 
    }
    return divisors.size();
}

signed main(){
    winton;
    int q;
    cin >> q;
    while(q--){
        int x;
        cin >> x;
        cout << solve(x) << endl;
    }
}