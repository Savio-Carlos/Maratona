#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define debug(x) cout << #x << " = " << x << "\n";
const int MAX = 2e5+7;
const int INF = INT_MAX;

signed main(){
    winton;
    int b, l;
    cin >> b >> l;
    vector<int> d(l);
    for(auto &u : d) cin >> u;
    int base = b+1;
    int resto = 0;
    for (int i = 0; i < l; i++) {
        int termo = d[i];
        if (!((l-1-i)&1)) {
            termo = -termo;
        }
        debug(termo);
        resto = (resto+termo % base + base) % base;
        debug(resto);
    }
    if (resto == 0) {
        cout << "0 0" << endl;
        return 0;
    }
    for (int i = 0; i < l; i++) {
        int reducao;
        if ((l-1-i)&1) {
            reducao = resto;
        } 
        else reducao = base - resto;

        if (d[i] >= reducao) {
            cout << i + 1 << " " << d[i] - reducao << endl;
            return 0;
        }
    }
    cout << "-1 -1" << endl;;
}