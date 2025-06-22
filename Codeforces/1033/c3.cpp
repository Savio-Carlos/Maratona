#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define debug(x) cout << #x << " = " << x << "\n";
const int MAX = 5e5+7;
const int INF = LLONG_MAX;

void solve(){
    int n, m;
    cin >> n >> m;
    int minisum = n; //cadeia de ums
    int maxsum = (n*(n+1))/2; //PA
    if (m < minisum || m > maxsum){
        cout << "-1" << endl;
        return;
    }
    int root = -1;
    for (int i = 1; i <= n; i++){
        if (i + n-1 == m){
            root = i;
            break;
        }
    }
    if (root != -1){
        cout << root << endl;
        int prev = root;
        for (int i = 1; i <= n; i++){
            if (i == root) continue;
            cout << prev << " " << i << endl;
            prev = i;
        }
        return;
    }
    int r = min(n, m - n + 1);
    bool pos = false;
    for (int i = r; i >= 2; i--){
        int tot = m - (i + n - 1);
        if (tot < 0) continue;
        int s = (i - 2) * (i - 1) / 2;
        int xismin = 0;
        if (tot > s){
            xismin = (tot-s+i-2)/(i-1);
        }
        int xismax = min(n-i, tot/(i-1));
        if (xismin <= xismax) {
            int used = xismin;
            int resto = tot - used * (i - 1);
            cout << i << endl;
            cout << i << " " << 1 << endl;
            vector<bool> comp(n + 1, false);
            comp[1] = true;
            comp[i] = true;
            for (int melhor = i - 2; melhor >= 1; melhor--) {
                if (resto >= melhor) {
                    int pegar = melhor + 1;
                    cout << i << " " << pegar << endl;
                    comp[pegar] = true;
                    resto -= melhor;
                }
            }
            for (int k = 1; k <= used; k++) {
                int nxt = k + k;
                if (nxt > n) break;
                cout << k << " " << nxt << endl;
                comp[nxt] = true;
            }
            for (int j = 2; j <= n; j++) {
                if (!comp[j]) {
                    cout << 1 << " " << j << endl;
                }
            }
            return;
        }   
    }
    cout << "-1" << endl;
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--) solve();
}