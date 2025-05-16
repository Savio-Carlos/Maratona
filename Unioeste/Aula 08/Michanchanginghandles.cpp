#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
using namespace std;
#define endl '\n'
#define int long long
const int MAXL = 1e6+7;

signed main() {_
    int n;
    cin >> n;
    vector<vector<string>> pares;
 
    while (n--) {
        string atual, nova;
        cin >> atual >> nova;
        bool novo = true;
        for (auto &u : pares) {
            size_t t = u.size();  // Use size_t for vector size
            if (atual == u[t-1]) {  // Safe access since t is size_t
                u.push_back(nova);  
                novo = false;
                break;
            }
        }
        if (novo) {
            pares.push_back({atual, nova});
        }
    }

    size_t si = pares.size();  // Use size_t for vector size
    cout << si << endl;
    for (size_t i = 0; i < si; i++) {  // Use size_t for loop index
        cout << pares[i][0] << " " << pares[i][pares[i].size()-1] << endl;  // Safe access
    }

    return 0;
}
