#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAX = 1e5+7;

signed main(){
    winton;
    int n, d;
    cin >> n >> d;
    vector<pair<int,int>> pontos;
    for (int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        pontos.push_back({a,b});
    }
    vector<int> valores;
    sort(all(pontos));
    int cur = pontos[0].second;
    for (int i = 1; i < pontos.size(); i++){
        cur += pontos[i].second;
        if (pontos[i].first - pontos[i-1].first > d){
            valores.push_back(cur-pontos[i].second);
            cur = pontos[i].second;
        }
    }   
    valores.push_back(cur);
    sort(rall(valores));
    //for (auto u : valores) cout << u << " ";
    if (valores.size() == 1) cout << valores[0] << endl;
    else cout << valores[0] + valores[1] << endl;
}