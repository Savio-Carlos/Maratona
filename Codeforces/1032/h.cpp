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
como seq[i] tem que ser entre l e r
eu vejo se o novo r faz com que eu tenha que eliminar um elemento da sequencia
ou seja se o novo r for menor que alguem da sequencia
quando eu removo ele e insiro o novo l eu garanto que naquela posicao vai ter uma cara menor que r
*/

template<typename T> ostream& operator<<(ostream& os, const multiset<T>& s) {
    os << "{ ";
    for(const auto& elem : s) {
        os << elem << " ";
    }
    os << "}";
    return os;
}

void solve(){
    int n;
    cin >> n;
    multiset<int> seq;
    for (int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;
        auto it = seq.upper_bound(r);
        if (it != seq.end()){
            seq.erase(it);
        }
        seq.insert(l);
        //cout << seq.size() << " ";
        cout << seq << endl;
    }
    cout << endl;
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--) solve();
}