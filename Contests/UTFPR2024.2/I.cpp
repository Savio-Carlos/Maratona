#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int n, m; cin >> n >> m;
    vector<pair<int, int>> ans;
    ans.push_back({0, 0});
    for(int i = 0; i < m; i++){
        int a, b, c; cin >> a >> b >> c;
        ans.push_back({b, 1});
        ans.push_back({c+1, -1});
    }
    ans.push_back({1e9+1, 0});

    sort(ans.begin(), ans.end());

    int maxi = 0, dia = 0;
    for(int i = 1; i < ans.size()-2; i++){
        ans[i].second += ans[i-1].second;
        if(ans[i].second > maxi){
            maxi = ans[i].second;
            dia = ans[i].first;
        }
    }

    cout << maxi << " " << dia << endl;
}
