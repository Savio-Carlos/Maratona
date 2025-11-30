#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);


#define f first;
#define s second;

signed main(){
    int n, m, l;
    cin >> n >> m >> l;
    vector<int> valor(m);
    for(int i=0;i<m;i++){
        cin >> valor[i];
    }
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
        v[i]--;
    }
    int soma=0, ans=LLONG_MAX;
    vector<int> qnt(m);
    for(int i=0;i<n;i++){
        if(qnt[v[i]] == 0){
            qnt[v[i]] = 1;
        } else {
            qnt[v[i]] *= 2;
        }
        soma += qnt[v[i]] * valor[v[i]];


        if(i -l >= 0){
            soma -= qnt[v[i-l]] * valor[v[i-l]];
            qnt[v[i-l]] /= 2;
        }

        if(i-l+1>=0) {ans = min(ans,soma);}
        // cout << soma <<endl;
    }
    cout << ans << endl;
}