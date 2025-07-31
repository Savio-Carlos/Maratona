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
const int MOD = 998244353;

int fastExpo(int base, int exp) {
    int r = 1;
    while(exp) {
        if (exp & 1) r = r * base % MOD;
        base = base * base % MOD;
        exp >>= 1;
    }
    return r;
}

int modinverse(int n) {
    return fastExpo(n, MOD - 2);
}

int modiv(int a, int b){
    return (a * modinverse(b))%MOD;
}

signed main(){
    winton;
    int n;
    cin >> n;
    vector<int> prob(MAX, 0);
    vector<int> freq(MAX,0);
    vector<vector<int>> kids(n);
    for (int i = 0; i < n; i++){
        int k;
        cin >> k;
        for (int j = 0; j < k; j++){
            int a;
            cin >> a;
            kids[i].push_back(a);
            prob[a] = (prob[a] + (modiv(1,n)%MOD) * (modiv(1,k))%MOD)%MOD;//chance desse presente ser escolhido no total
            freq[a]++;
        }
    }
    int ans = 0;
    for (int i = 1; i < MAX; i++){
        if (!prob[i])continue;
        // debug(prob[i]);
        // debug(freq[i]);
        ans = (ans + ((modiv(freq[i],n))%MOD)*prob[i]%MOD) % MOD;//chance desse presente ser escolhido * chance de escolher uma crianca que quer esse presente = chance de ser valido
    }
    cout << ans%MOD << endl;
}