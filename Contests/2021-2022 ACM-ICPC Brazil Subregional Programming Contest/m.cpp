#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define debug(x) cout << #x << " = " << x << "\n";
const int MAX = 1e5+7;
const int INF = INT_MAX;

queue<int> kings [MAX];
int morreu[MAX];

signed main(){
    winton;
    int q;
    cin >> q;
    int id = 2;
    stack<int> past;
    int cur = 1;
    while(q--){
        int tp; cin >> tp;
        if (tp == 1){
            int p; cin >> p;
            kings[p].push(id++);
        }
        else {
            int p; cin >> p;
            morreu[p] = 1;
            if (p == cur){
                //rei morreu, se ele tiver filhos entao e ele, toda vez que eu vou pra um filho novo eu insiro na minha past
                //se ele nao tem filhos entao eu volto ao meu ultimo past que e o pai dele e percorro ate ou estar vazio (e dai eu volto)
                //ou se o cara tiver vivo ele vira o rei
                while(morreu[kings[cur].top()]) kings[cur].pop();
                if (!kings[cur].empty()){//morri e tenho filhos, meu filho vira rei
                    past.insert(cur);
                    cur = kings[cur].top();
                }
                else {
                    while(kings[past.top()].empty()) past.pop();//if morri e n tenho filhos, vou voltando pelo past ate encontrar alguem com filhos vivos
                    while(morreu[kings[cur].top()]) kings[cur].pop();
                }
                
            }
            else cout << cur << endl;
        }   
    }
}