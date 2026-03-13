#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)

const int MAX = 257;

char grid[MAX][MAX];
vector<int> h[MAX];

int area(vector<int> v){
    int ret = 0;
    stack<int> s;
    v.insert(v.begin(), -1);
    v.insert(v.end(), -1);
    s.push(0);

    // for (auto u : v) cout << u << " ";
    // cout << endl;
    for (int i = 0; i < v.size(); i++){
        while(v[s.top()] > v[i]){
            int he = v[s.top()];
            s.pop();
            ret = max(ret, he*(i-s.top()-1));

        }
        s.push(i);
    }
    return ret;
}

signed main(){
    fastio;
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }
    int ans = 0;

    for (int j = 0; j < m; j++){
        for (int i = 0; i < n; i++){
            int dist = 0;
            if (!i){
                dist = ((grid[i][j] == '.') ? 0 : 1);
            }
            else if (grid[i][j] == '.') dist = 0;
            else{
                dist = h[i-1].back() + 1;
            }
            h[i].push_back(dist);
        }
    }
    
    for (int i = 0; i < n; i++){
        ans = max(ans, area(h[i]));
    }
    cout << ans << endl;
    
}