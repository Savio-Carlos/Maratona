#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<pair<int,int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

bool valid(int x, int y, int n, int m){
    return (x>=0 && x<n && y>=0 && y<m);
}

int main() {
    int n, m, x, y, k, ans = 1;
    cin >> n >> m >> x >> y >> k;
    x--; y--;
    pair<int,int> start = {x,y};

    vector<vector<int>> grid(n, vector<int>(m, 0));

    for (int i = 0; i < k; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        grid[a][b] = 2;
    }

    queue<pair<int,int>> q;
    q.push(start);
    grid[start.first][start.second] = 1;

    while(!q.empty()){
        pair<int,int> atual = q.front();
        q.pop();

        for (const auto& move : moves) {
            int novox = atual.first + move.first;
            int novoy = atual.second + move.second;
            if (valid(novox,novoy,n,m) && grid[novox][novoy]==0){
                q.push({novox,novoy});
                grid[novox][novoy] = 1;
                ans++;
            }
        }
    }
    cout << ans << endl;
}