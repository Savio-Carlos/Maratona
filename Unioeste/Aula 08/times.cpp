#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
using namespace std;
#define endl '\n'
#define int long long
const int MAXL = 1e6+7;

signed main() {_
    int n, t;
    cin >> n >> t;
    vector<pair<int,string>> players(n);
    vector<vector<string>> teams(t, vector<string>());
    for(int i = 0; i < n; i++){
        int a;
        string nome;
        cin >> nome >> a;
        players[i].first = a;
        players[i].second = nome;
    }
    sort(players.begin(), players.end(), greater());
    
    for (int i = 0; i < t; i++){
        for(int j = i; j < n; j+=t){
            teams[i].push_back(players[j].second);
        }
    }

    for (int i = 0; i < t; i++){
        cout << "Time " << i << endl;
        sort(teams[i].begin(), teams[i].end());
        for (auto u : teams[i]){
            cout << u << endl;
        }
        cout << endl;
    }
}