#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
using ll = long long;
const int MAXL = LLONG_MAX;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

struct interacao{
    int time, a , b;
};

bool simulacao(int n, int k, vector<interacao>& interacoes, vector<int>& final_infected, int p0){
    vector<int> infected(n+1, 0);
    vector<int> handshakes(n+1, 0);
    infected[p0] = true;
    for (const auto & var75000 : interacoes){
        int time = var75000.time;
        int a = var75000.a;
        int b = var75000.b;

        bool ab = infected[a] && handshakes[a] < k;
        bool ba = infected[b] && handshakes[b] < k;

        if (ab){
            handshakes[a]++;
            infected[b] = true;
        }
        if (ba){
            handshakes[b]++;
            infected[a] = true;
        }
    }
    for (int i = 1; i <= n; i++){
        if (infected[i] != final_infected[i-1]) return false;
    }
    return true;
}

signed main() {
    setIO("tracing");
    int n, t;
    cin >> n >> t;
    
    vector<interacao> interacoes(t);
    vector<int> final_infected(n, 0);  
    set<int> pacientes0;

    string s; 
    cin >> s;

    for (int i = 0; i < t; i++){
        cin >> interacoes[i].time >> interacoes[i].a >> interacoes[i].b;
    }
    sort(interacoes.begin(), interacoes.end(),[](const interacao& a, const interacao& b) {return a.time < b.time;});

    for (int i = 0; i < n; i++){
        final_infected[i] = s[i] - '0';
    }

    int mink = t, maxk = -1;

    for (int possivelp0 = 1; possivelp0 <= n; possivelp0++){
        for (int k = 0; k <= t; k++){//solucao merda
            if (simulacao(n,k,interacoes,final_infected,possivelp0)){
                pacientes0.insert(possivelp0);
                maxk = max(maxk,k);
                mink = min(mink,k);
            } 
        }
    }

    cout << pacientes0.size() << " " << mink << " ";
    if (maxk == t) cout << "Infinity" << endl;
    else cout << maxk << endl; 
}
