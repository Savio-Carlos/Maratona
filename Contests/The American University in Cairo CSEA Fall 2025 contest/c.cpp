#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define int long long
#define ld long double

#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

/*
pegar todos os pares possiveis de a,b e tirar aqueles onde a divide b ou b divide a
para contar quantos numeros a<= b dividem b, posso usar tau
por simetria se x numeros dividem b, x numeros dividem a
ans = n*n - 2*x + n (pares a,a que sao removidos duas vezes) 
*/

const int MAX = 1e6+7;
int tau[MAX];
int pfx[MAX];

void build() {
    for (int i = 1; i < MAX; i++) {
        for (int j = i; j < MAX; j += i) {
            tau[j]++;
        }
    }
    pfx[0] = 0;
    for (int i = 1; i < MAX; i++) {
        pfx[i] = pfx[i-1] + tau[i];
    }
}

void solve() {
    int n;
    cin >> n;
    int k = pfx[n];
    int ans = (n * n) - (2 * k) + n;
    cout << ans << endl;
}

signed main() {
    fastio;
    build();
    int t;
    cin >> t;
    while (t--) solve();
}
