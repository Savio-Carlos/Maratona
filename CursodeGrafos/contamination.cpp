#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXT = 55;
int n, m;

vector<pair<int,int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool valid(int x, int y){
    return (x>=0 && x<n && y>=0 && y<m);
}

void floodfill(vector<string>& grid, int x, int y){
    queue<pair<int, int>> q;
    q.push({x, y});
        while(!q.empty()){
            pair<int,int> atual = q.front();
            q.pop();

            for (const auto& move : moves) {
                int novox = atual.first + move.first;
                int novoy = atual.second + move.second;
                if (valid(novox,novoy) && grid[novox][novoy] == 'A'){
                    grid[novox][novoy] = 'T';
                    q.push({novox,novoy});
                }
            }
        }
}

int main() {
    while(cin >> n >> m){
        if (n == 0 && m == 0){
            return 0;
        }
        vector<string> grid(n);
        bool visited[n][m] = {false};

        for (int i = 0; i < n; ++i) {
            cin >> grid[i];
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 'T') {
                    floodfill(grid, i, j);
                }
            }
        }
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cout << grid[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }

}