// Source: https://usaco.guide/general/io
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n = 0; cin >> n; //Aulas
    int temp1_aulas = 0, temp2_aulas = 0;
    vector<int> aulas(n);
    for(int i=0;i<n;i++){
        cin >> temp1_aulas;
        temp2_aulas += temp1_aulas;
        aulas.push_back(temp2_aulas);
    }

    int m = 0;cin >> m; //Dias
    vector<int>dias(m);
    
    for(int i=0;i<m;i++){
        cin >> dias[i];
        auto it = lower_bound(aulas.begin(), aulas.end(), dias[i]);
        cout << *it << " " << it - aulas.begin() + 1 << "\n";
    }
}