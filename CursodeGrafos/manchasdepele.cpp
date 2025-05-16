#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXT = 1001;
int n, m;
vector<pair<int,int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool visited[MAXT][MAXT];
bool grid[MAXT][MAXT];

bool valid(int x, int y){
    return (x>=0 && x<n && y>=0 && y<m);
}

void bfs(int x, int y){
    queue<pair<int,int>> q;
    q.push({x,y});
    visited[x][y] = true;

    while(!q.empty()){
        pair<int,int> atual = q.front();
        q.pop();

        for (const auto& move : moves) {
            int novox = atual.first + move.first;
            int novoy = atual.second + move.second;
            if (valid(novox,novoy) && !visited[novox][novoy] && grid[novox][novoy] == 1){
                q.push({novox,novoy});
                visited[novox][novoy] = true;
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 1 && !visited[i][j]) {
                bfs(i, j);
                cnt++;
            }
        }
    }

    cout << cnt << endl;
}