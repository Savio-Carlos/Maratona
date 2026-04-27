#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int long long
#define ld long double
#define endl '\n'

#define winton ios_base::sync_with_stdio(false),cin.tie(0)

const int MAX = 100;

int grid[MAX][MAX];

signed main(){
    winton;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        grid[x][y] = -1;
    }
    string s;
    cin >> s;

    int x = 0, y = 0;

    map<int,pair<int,int>> dir;
    dir['F'] = {0,1};
    dir['T'] = {0,-1};
    dir['D'] = {1,0};
    dir['E'] = {-1,0};

    for (int i = 0; i < s.size(); i++){
        auto [dx,dy] = dir[s[i]];
        int nx = x + dx;
        int ny = y + dy;
        if (nx >= MAX || nx < 0 || ny >= MAX || ny < 0 || grid[nx][ny] == -1) continue;
        x = nx;
        y = ny;
    }
    cout << x << " " << y << endl;

}