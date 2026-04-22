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
const int MAX = 2e5+7;
const int MOD = 1e9+7;
const int INF = LLONG_MAX;

/*
DKDKDDDDK
111212113

D (1:0)
DK (1:1)
DKD (2:1)
DKDK -> DK DK (1:1) = (2:2) gcd = 2
DKDKD (3:2)
DKDKDD -> DDK KDD (2:1) = (4:2) gcd = 2
DKDKDDD (5:2)
DKDKDDDD (6:2) X aqui a gente nunca encontrou o ratio 3:1 antes entao isso marca que n e possivel dividir
DKDKDDDDK -> DKD KDD DDK (2:1) = (6:3) gcd = 3 

os dois ratios tem que ser multiplos, seu gcd nao pode ser 1! (eu acho)
ordem importa
*/

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int d = 0, k = 0;
    vector<int> ans;
    map<pair<int,int>,int> cnt;
    for (int i = 0; i < n; i++){
        if (s[i] == 'K') k++;
        else d++;

        if (!d || !k) ans.push_back(i+1);
        else{
            int g = gcd(d,k);
            pair<int,int> ratio = {d/g,k/g};
            ans.push_back(++cnt[ratio]);
        }
    }
    for (auto u : ans) cout << u << " ";
    cout << endl;
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--) solve();
}