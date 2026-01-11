#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

signed main(){
    fastio;
    int n;
    if(!(cin >> n)) return 0;
    
    map<int, vector<int>> mp;
    vector<int> ones;
    int min_x = 2e9, max_x = -2e9;

    for(int i=0; i<n; i++){
        int x, y;
        cin >> x >> y;
        min_x = min(min_x, x);
        max_x = max(max_x, x);
        
        if(y == 1) ones.push_back(x);
        else mp[x].push_back(y);
    }

    vector<pair<int,int>> ans;
    // Função para evitar vértices duplicados consecutivos
    auto add = [&](int x, int y){
        if(!ans.empty() && ans.back() == make_pair(x, y)) return;
        ans.push_back({x, y});
    };

    // --- CONSTRUÇÃO DO CASCO SUPERIOR (Upper Hull) ---
    // Começamos na esquerda, altura 2
    add(min_x, 2);

    // Identificar blocos contíguos de colunas com y > 1
    vector<vector<int>> blocks;
    if(!mp.empty()){
        vector<int> cur;
        int last = -10;
        for(auto& [x, ys] : mp){
            if(x > last + 1 && !cur.empty()){
                blocks.push_back(cur);
                cur.clear();
            }
            cur.push_back(x);
            last = x;
        }
        if(!cur.empty()) blocks.push_back(cur);
    }

    int current_hull_x = min_x;

    for(auto& block : blocks){
        int start_x = block.front();
        int end_x = block.back();
        int sz = block.size();

        // Conectar ao início do bloco pelo nível 2 (ponte sobre gaps)
        add(start_x, 2); 

        // Lógica de Direção (Snake)
        // Padrão: Começar SUBINDO (Up) -> índice 0 Up, 1 Down...
        // Exceção: Se termina em 10^9, PRECISA terminar DESCENDO.
        // Se sz é ímpar, padrão terminaria Up. Então forçamos start Down.
        bool force_start_down = (end_x == 1000000000 && sz % 2 != 0);

        if(force_start_down){
            // Helper Esquerdo: Coluna fantasma para inverter paridade
            int helper_x = start_x - 1;
            auto& first_col = mp[start_x];
            sort(first_col.begin(), first_col.end());
            int top = first_col.back();

            add(helper_x, 2);
            add(helper_x, top);
            // Agora estamos no topo, prontos para descer a coluna start_x
        }

        for(int i=0; i<sz; i++){
            int x = block[i];
            auto& ys = mp[x];
            sort(ys.begin(), ys.end());

            bool is_up = (force_start_down ? (i % 2 != 0) : (i % 2 == 0));

            if(is_up){
                // SUBINDO: Base(2) -> Topo
                add(x, 2); 
                for(int y : ys) add(x, y);
            } else {
                // DESCENDO: Topo -> Base(2)
                // O add conecta automaticamente ao topo anterior
                add(x, ys.back()); // Garante conexão pelo teto
                for(int k=ys.size()-1; k>=0; k--) add(x, ys[k]);
                add(x, 2); 
            }
        }
        
        // Final do bloco
        bool last_is_up = (force_start_down ? ((sz-1)%2!=0) : ((sz-1)%2==0));
        
        if(last_is_up){
            // Se terminou no alto, precisamos descer. Usamos helper à direita.
            // Isso nunca acontece se x=10^9.
            add(end_x + 1, 2);
            current_hull_x = end_x + 1;
        } else {
            current_hull_x = end_x;
        }
    }

    // Estender o casco até o max_x (pelo nível 2) para cobrir todos os 'ones'
    add(max_x, 2);

    // --- CONSTRUÇÃO DO RETORNO (Lower Hull) ---
    // Descer para y=1 e voltar coletando os ones
    add(max_x, 1);
    
    sort(ones.rbegin(), ones.rend());
    for(int x : ones) add(x, 1);
    
    // Fechar o ciclo voltando ao início
    add(min_x, 1);
    add(min_x, 2); // Fecha com o ponto inicial

    cout << ans.size() << endl;
    for(auto p : ans) cout << p.first << " " << p.second << endl;
}