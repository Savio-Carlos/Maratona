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
const int INF = LLONG_MAX;
const int MOD = 998244353;

struct circle{
    ld x, y, raio;
};

signed main(){
    winton;
    ld x1, x2, y1, y2;
    int n;
    cin >> x1 >> y1 >> x2 >> y2 >> n;
    vector<circle> cs(n);
    for (int i = 0; i < n; i++){
        ld a, b, r;
        cin >> a >> b >> r;
        cs[i] = {a,b,r};
    }
    ld A = x2 - x1;
    ld B = y2 - y1;
    ld C = A * A + B * B;
    ld ans = 0;
    for (int i = 0; i < n; i++){   
        auto [x, y, r] = cs[i]; 
        // vetor de P1 até o centro do círculo
        ld wx = x - x1;
        ld wy = y - y1;

        // parâmetro t da projeção ortogonal de (x,y) sobre o segmento
        ld t = (wx * A + wy * B) / C;

        // restringe t dentro de [0,1] para ficar no segmento e não na reta infinita
        t = max((ld)0.0, min((ld)1.0, t));

        // ponto projetado no segmento
        ld px = x1 + t * A;
        ld py = y1 + t * B;

        // distância entre o centro e esse ponto projetado
        ld dx = x - px;
        ld dy = y - py;
        ld dist = sqrt(dx*dx + dy*dy);

        // se o segmento cruza (ou passa dentro de) o círculo, soma (r − dist)
        if (dist <= r) {
            ans += r - dist;
        }
    }
    cout << fixed << setprecision(4) << ans << endl;
}