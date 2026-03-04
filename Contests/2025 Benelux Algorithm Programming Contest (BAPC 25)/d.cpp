#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false),cout.tie(0),cin.tie(0) 

signed main(){
    fastio;
    int n;
    cin >> n;

    vector<vector<int>> grid(n);
    vector<int> todos;
    for (int i = 0; i < n; i++){
        int k;
        cin >> k;
        grid[i].resize(k);
        for (int j = 0; j < k; j++){
            cin >> grid[i][j];
            todos.push_back(grid[i][j]);
        }
    }
    //compressao de coordenada
    sort(all(todos));
    todos.erase(unique(all(todos)), todos.end());
    int m = todos.size();
    vector<vector<int>> comp(n);
    for (int i = 0; i < n; i++){
        comp[i].resize(grid[i].size());
        for (int j = 0; j < grid[i].size(); j++){
            comp[i][j] = lower_bound(all(todos), grid[i][j]) - todos.begin();
        }
    }

    vector<vector<int>> mp(m);
    vector<int> compartilha(n, -1);//vetor pra saber o primeiro valor que o vetor i compartilha com o vetor atual
    
    for (int i = 0; i < n; i++){
        vector<int> aux;//vetor pra guardar quais vetores compartilham um valor com o vetor atual, resetado a cada vetor
        for (int j = 0; j < comp[i].size(); j++){
            int x = comp[i][j];
            // x = valor atual comprimido
            for (int u : mp[x]){
                //para todos as mensagens que contem o x atual
                if (compartilha[u] == -1){
                    //se o vetor nao compartilha nenhum valor, coloca que o vetor u compartilha o valor x
                    compartilha[u] = grid[i][j];
                    aux.push_back(u);
                } 
                else {
                    //se compartilha um valor ja, achamos a resposta
                    cout << compartilha[u] << " " << grid[i][j] << " " << i + 1 << " " << u + 1 << endl;
                    return 0;
                }
            }
            mp[x].push_back(i);
        }
        for (int u : aux) compartilha[u] = -1;
    }

    cout << "impossible" << endl;
}