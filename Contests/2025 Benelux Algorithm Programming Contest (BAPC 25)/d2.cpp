#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false),cout.tie(0),cin.tie(0) 

struct no{
    int valor;
    int pai;
    bool mensagem;
}

signed main(){
    fastio;
    int n;
    cin >> n;

    vector<vector<int>> v(n);

    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        for(int j = 0; j < k; j++){
            int x;
            cin >> x;
            v[i].push_back(x);
        }
    }

    map<int, vector<int>> mp;
    for(int i = 0; i < n; i++){
        for(auto w:v[i]){
            mp[w].push_back(i);
        }
    }

    // Insere os valores do primeiro array na fila
    queue<no> q;
    for(auto val:v[0]){
        q.push({val,0,false});
    }

    // Para guardar o grafo
    vector<map<int,int>> grafo(n);

    // Para evitar loops desnecessarios
    vector<bool> visited_msg(n);
    vector<bool> valores(1e5+1);

    while(!q.empty()){

        if(q.top().mensagem){ // Se for uma mensagem

            // Olha os valores do array
            for(auto val:v[q.top().valor]){

                // Insere os valores da mensagem
                if(q.top().valor)
            }
        }
    }

}