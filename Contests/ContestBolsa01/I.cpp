#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long
#define vi vector<int>
#define pb push_back
const int MAXN = 1e3+7;
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};

signed main() {_
    int n, m;
    cin >> n >> m;
    char grid[n][m];
    pair<int,int> st;
    int dir;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            char a = grid[i][j];
            if (a != '#' && a != '.') {
                st = {i,j};
                if (a == 'R') dir = 0;
                else if (a == 'U') dir = 1;
                else if (a == 'L') dir = 2;
                else dir = 3;
            }
        }
    }

    vector<vector<bool>> bar(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '#') {
                bar[i][j] = true;
            }
        }
    }

    set<tuple<int, int, int>> visitedState;
    set<pair<int, int>> visited;

    int curx = st.first;
    int cury = st.second;
    visited.insert({curx, cury});
    visitedState.insert({curx, cury, dir});

    while (1) {
        int nxtx = curx + dx[dir];
        int nxty = cury + dy[dir];
        bool moved = false;

        if (nxtx >= 0 && nxtx < n && nxty >= 0 && nxty < m && !bar[nxtx][nxty]) {
            auto nstate = make_tuple(nxtx, nxty, dir);
            if (visitedState.count(nstate)) {
                break;
            }
            visitedState.insert(nstate);
            visited.insert({nxtx, nxty});
            curx = nxtx;
            cury = nxty;
            moved = true;
        } else {
            bool found = false;
            for (int i = 1; i <= 4; i++) {
                int ndir = (dir + i) % 4;
                auto rrr = make_tuple(curx, cury, ndir);
                if (visitedState.count(rrr)) {
                    cout << visited.size() << endl;
                    return 0;
                }
                visitedState.insert(rrr);

                int nx = curx + dx[ndir];
                int ny = cury + dy[ndir];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !bar[nx][ny]) {
                    auto move_state = make_tuple(nx, ny, ndir);
                    if (visitedState.count(move_state)) {
                        cout << visited.size() << endl;
                        return 0;
                    }
                    visitedState.insert(move_state);
                    visited.insert({nx, ny});
                    curx = nx;
                    cury = ny;
                    dir = ndir;
                    found = true;
                    break;
                }
            }
            if (!found) break;
        }
    }
    cout << visited.size() << endl;
}