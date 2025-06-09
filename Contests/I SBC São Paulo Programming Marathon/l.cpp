#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAX = 2e5+7;
const int INF = INT_MAX;

signed main(){
    winton;
    int n;
    cin >> n;
    vector<vector<int>> livros(n);
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        while(x--){
            int a;
            cin >> a;
            livros[i].push_back(a);
        }
    }
    if (n >= 3) cout << "S" << endl;
    else if (n == 2){
        vector<bool> pos(2);
        for (int i = 0; i < n; i++){
            if (livros[i].empty()) continue;
            int base = livros[i][0];
            for (auto u : livros[i]){
                if(u != base) pos[i] = true;
            }
        }
        if (pos[0] && pos[1])cout << "N" << endl;
        else cout << "S" << endl;
    }
    else cout << "S" << endl;
}