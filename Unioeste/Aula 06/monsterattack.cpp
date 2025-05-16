#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e9+7;

bool solve(int n, int k, vector<int>& vida, vector<int>& posicoes){
    vector<pair<int,int>> monstros;
        for (int i = 0; i < n; i++){
            monstros.emplace_back(abs(posicoes[i]), vida[i]);
        }
        sort(monstros.begin(), monstros.end());
        int soma = 0;
        for(auto& [posicao, vida] : monstros){
            soma += vida;
            if (soma > k*posicao) return false;
        }
    return true;
}

signed main() {
    int t; cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> posicoes(n), vida(n);
        for (int i = 0; i < n; i++){
            cin >> vida[i];
        }
        for (int i = 0; i < n; i++){
            cin >> posicoes[i];
        }

        bool ans = solve(n,k,vida,posicoes);
        if (ans) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}