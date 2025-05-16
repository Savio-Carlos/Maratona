#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAXN = 1e3+7;
const int MAXM = 15;

vector<pair<int,int>> stuffings(MAXN);
int n, m, c0, d0, usage[MAXN], qtd[MAXN], gain = 0;
int memo[MAXM][MAXN];

int solve(int index, int dough){
    if (index > m) {
        return dough/c0 * d0;
    }
    
    int cur = 0;
    for (int i = 0; i <= m; i++){
        if (qtd[i] >= usage[i]){
            qtd[i] -= usage[i];
            cur = max(cur, solve(cost + stuffings[i].first, gain + stuffings[i].second));
        }
    }
    return gain + cur;
}

signed main(){
    winton;
    cin >> n >> m >> c0 >> d0;
    for (int i = 1; i <= m; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        qtd[i] = a;
        usage[i] = b;
        stuffings[i] = {c,d};
    }
    int ans = solve(0,0);

    cout << ans << endl;
}