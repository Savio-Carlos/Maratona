#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int long long
#define ld long double
#define endl '\n'

#define winton ios_base::sync_with_stdio(false),cin.tie(0)

pair<int,int> dir[] = {{1,1},{1,0},{1,-1},{0,1},{0,0},{0,-1},{-1,1},{-1,0},{-1,-1}};

signed main(){
    winton;
    int n, m, b;
    cin >> m >> n >> b;
    
    vector<vector<int>> cur(n, vector<int>(m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> cur[i][j];
            // cur[i][j] *= 9;
        }
    }
    while(b--){
        vector<vector<int>> prox(n, vector<int>(m));
        
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                int sum = 0;
                for (int k = 0; k < 9; k++){
                    auto [dx, dy] = dir[k];
                    int nx = (i + dx + n) % n;
                    int ny = (j + dy + m) % m;
                    sum += cur[nx][ny] * 9;
                }
                prox[i][j] = sum / 9;
            }
        }
        cur = prox;
    }
    set<int> st;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            st.insert(cur[i][j]);
        }
    }
    // for (auto it : st) cout << it << endl;
    // st.erase(0LL);
    cout << st.size() << endl;
}

