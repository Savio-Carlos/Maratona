#include <iostream>
#include <vector>
#include <algorithm>
#define int long long

using namespace std;
 
signed main(){
 
    cin.tie(0)->sync_with_stdio(0);
 
    vector<int> aulas;
    int n; cin >> n;
 
    int sum = 0;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        sum += x;
        aulas.push_back(sum);
    }
 
    int m; cin >> m;
    int sum = 0;
    int v_anterior = 0;
    vector<pair<int,int>> dias(m);
    for (int i = 0; i < m; i++){
        int x;
        cin >> x;
        dias[i] = {x,i};
    }
    sort(dias.begin(), dias.end());

    vector<pair<int,int>> ans(m);
    for (int i = 0; i < m; i++){
        
        for (int j = v_anterior; j < n; j++){
            sum += aulas[j];
            if (sum >= dias[i].first){

                ans[dias[i].second] = {sum, j+1};
                v_anterior = j;
                break;

            }
        }
        
    }
    for (auto [u, v] : ans) cout << u << " " << v << '\n';
    return 0;
}