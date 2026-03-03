#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false),cout.tie(0),cin.tie(0) 


ld funcao(pair<int,int> &fab, ld &t){
    ld tempo = t - 2 * fab.second;
    if (tempo < 0.0) return 0;
    return tempo * fab.first;
}

ld faz_tudo(vector<pair<int,int>> &v, ld &t){
    ld total = 0;
    for(int i = 0; i < v.size(); i++){
        total += funcao(v[i], t);
    }
    return total;
}

signed main(){
    fastio;
    ld w;
    int n;
    cin >> n >> w;
    vector<pair<int,int>> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].first >> v[i].second;
    }
    ld esq = 0, dir = 1e18, meio = 1e5;
    for(int i = 0; i < 100; i++){
        meio = (esq + dir) / 2.0;
        if(faz_tudo(v, meio) >= w){
            dir = meio;
        } else {
            esq = meio;
        }
    }
    cout << fixed << setprecision(20) << meio << endl;

}