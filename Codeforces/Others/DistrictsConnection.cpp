#include <bits/stdc++.h>
using namespace std;
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long
#define ld long double
const int MAXS = 1e5;

signed main() {
    winton;
    int t; cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> districts(n), gang0;
        for (int i = 0; i < n; i++){
            cin >> districts[i];
            if (districts[i] == districts[0] && i > 0) gang0.push_back(i+1);
        } 
        if (count(all(districts), districts[0]) == n){
            cout << "NO" << endl;
            continue;
        }
        vector<pair<int,int>> connections;
        for (int i = 1; i < n; i++){
            if (districts[i] != districts[0])connections.push_back({1, i+1});
        }
        int i = 0;
        while (districts[i] == districts[0]) i++;
        for (auto u : gang0){
            connections.push_back({i+1, u});
        }
        cout << "YES" << endl;
        for (auto [u,v] : connections) cout << u << " " << v << endl;
    }    
}