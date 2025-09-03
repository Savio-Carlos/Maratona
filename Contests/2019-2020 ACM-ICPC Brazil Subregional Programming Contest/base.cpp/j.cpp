#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'

/*
regras:
curinga nunca pode ser passado logo apos ser recebido
passar a carta q menos aparece (se estiver mais de uma pegar a menor)
estado vencedor 
*/

signed main(){
    int n, k; cin >> n >> k;
    vector<multiset<int>> v(n);
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        for(int j = 0; j < s.size(); j++){
            if(s[j] == 'A') v[i].insert(1);
            else if(s[j] == 'D') v[i].insert(10);
            else if(s[j] == 'Q') v[i].insert(11);
            else if(s[j] == 'J') v[i].insert(12);
            else if(s[j] == 'K') v[i].insert(13);
            else v[i].insert(s[j]-'0');
        }
    }
    //cout << "passou da leitura\n";
    /*
    passar posicao atual, estado do coringa e string
    */
    vector<int> curinga(n, 0);
    k = k - 1;
    int pos = k;
    curinga[k] = 1;

    auto is_winner = [&](int i) -> bool {
        if(curinga[i] != 0) return false;
        if(v[i].size() != 4) return false;
        int lst = *v[i].begin();
        for(auto u : v[i]) if(u != lst) return false;
        return true;
    };

    while(true){
        //se algum deles estiver em estado vencedor em algum momento x pre jogada
        for(int i = 0; i < n; i++){
            if(is_winner(i)){
                cout << i+1 << endl;
                return 0;
            }
        }

        //no caso de ter um curinga, nn adiciono nada, so mando com o estado do curinga mudado
        //quem esta com o curinga esta com estado 1, mas so pode passar o curinga quando estiver com estado 2
        if(curinga[pos] == 2){
            curinga[pos] = 0;
            pos = (pos+1)%n;
            curinga[pos] = 1;
            //cout << "erro esta no 1 if\n";
        }else{
            if(curinga[pos] == 1) curinga[pos] = 2;
            //assim eu garanto q pego oq aparece menos vezes e tbm o menor deles
            vector<int> freq(14, 0);

            for(auto u : v[pos]) freq[u]++;
            int mn = 150, idx = -1;
            for(int i = 1; i <= 13; i++){
                if(freq[i] > 0 && freq[i] < mn){
                    mn = freq[i];
                    idx = i;
                }            
            }
            //cout << idx << " " << mn << endl;
            //cout << "erro esta no 2 if\n";
            v[pos].erase(v[pos].find(idx));
            pos = (pos+1)%n;
            v[pos].insert(idx);

        }

        //checando pos jogada
        for(int i = 0; i < n; i++){
            if(is_winner(i)){
                cout << i+1 << endl;
                return 0;
            }
        }
    }
}