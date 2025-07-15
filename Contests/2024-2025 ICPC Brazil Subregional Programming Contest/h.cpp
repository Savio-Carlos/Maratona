#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
const int MAX = 2e4+7;

/*
como numero total de * <= 16
podemos guardar as posicoes desses asteriscos e depois iterar por todas as combinacoes possiveis
em uma mask espcifica, se o bit for 1 entao substituimos na string por 1, se for 0 por 0
pra isso guardamos a posicao de cada * e em qual string ele esta
para ficar mais facil na hora de fazer bitmask
*/


signed main(){
    string n, m;
    cin >> m >> n;
    vector<pair<int,int>> as;
    for (int i = 0; i < m.size(); i++){
        if (m[i] == '*') as.push_back({i,1});
    }
    for (int i = 0; i < n.size(); i++){
        if (n[i] == '*') as.push_back({i,0});
    }
    int k = as.size();
    for (int i = 0; i < (1<<k); i++){
        string mlinha = m;
        string nlinha = n;

        for (int j = 0; j < k; j++){
            if (i&(1<<j)){
                if (as[j].second){
                    mlinha[as[j].first] = '1';
                }
                else nlinha[as[j].first] = '1';
            }
        }   
        int resto = 0, MOD = 0;;
        for (auto &c : nlinha){
            if (c == '*') c = '0';
            MOD = (MOD*2 + c - '0') ;
        }
        for (auto &c : mlinha){
            if (c == '*') c = '0';
            resto = (resto*2 + c - '0') % MOD ;
        }
        if (resto == 0) {
            cout << mlinha << endl;
            return 0;
        }
    }
}