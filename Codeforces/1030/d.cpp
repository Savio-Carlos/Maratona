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
const int INF = INT_MAX;

/*

*/

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> positions(n), delays(n);
    for (int &u : positions) cin >> u;
    for (int &u : delays) cin >> u;
    int q;
    cin >> q;
    while(q--){
        int x; cin >> x;
        int st = n - (positions.end() - lower_bound(positions.begin(), positions.end(), x));
        int stdiff = positions[st] - x;
        int cur = st, tempo = stdiff, estado = stdiff;
        estado %= k;
        int visited[n][k][2] = {};

        int direcao = 1;
        // if ((positions[st]*tempo) % k == delays[st]) direcao = 0;
        // else direcao = 1;

        bool pos = false;

        int nxt = direcao ? cur+1 : cur-1;

        while (cur >= 0 && cur < n && !visited[cur][estado][direcao]){
            visited[cur][estado][direcao] = 1;
            debug(tempo%k);
            debug(delays[cur]);
            if ((tempo % k) == delays[cur])direcao = !direcao;
            nxt = direcao ? cur+1 : cur-1;
            debug(cur);
            debug(nxt);
            if (nxt == n){
                pos = true;
                break;
            }
            if (nxt == -1) break;
            int diff = abs(positions[cur] - positions[nxt]);
            tempo += diff;
            estado = tempo%k;
            cur = nxt;
           cout << "------------------------------------\n";
        }
        if (pos) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}

signed main(){
    //winton;
    int t;
    cin >> t;
    while(t--) solve();
}