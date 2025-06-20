#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define debug(x) cout << #x << " = " << x << "\n";
const int MAX = 2e5+7;
const int INF = LLONG_MAX;

// (-1,0) (1,0) (0,-1) (0,1)
vector<pair<int,int>> moves = {{1,0},{0,1},{-1,0},{0,-1}};
int n, m;

bool floodfill(int mx, int x, int y, const vector<vector<int>> &grid){
    int visited[n+1][m+1]={};
    queue<pair<int,int>> q;
    q.push({x,y});
    while(!q.empty()){
        auto [curx, cury] = q.front();
        q.pop();
        //cout << curx << " " << cury << endl;
        for(auto [dx,dy] : moves){
            int novox = curx+dx;
            int novoy = cury+dy;
            if (novox >= 0 && novox < n && novoy >= 0 && novoy < m){
                int valor = (mx | grid[novox][novoy]);
                if (valor == mx && !visited[novox][novoy]){
                    visited[novox][novoy] = 1;
                    q.push({novox,novoy});
                }
            }
        }
    }
    return visited[n-1][m-1];
}

signed main(){
    winton;
    int x, y;
    cin >> n >> m >> x >> y;
    vector<vector<int>> grid(n,vector<int>(m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }
    int l = 0, r = INF;
    int ansT, ansG;
    while(l < r){
        int mid = l + (r-l)/2;
        if(floodfill(mid,0,0,grid)){
            r = mid;
            ansT = mid;
        }
        else {
            l = mid+1;
        }
    }
    l = 0, r = INF;
    while(l < r){
        int mid = l + (r-l)/2;
        if(floodfill(mid,x-1,y-1,grid)){
            r = mid;
            ansG = mid;
        }
        else {
            l = mid+1;
        }
    }
    cout << ansT << " " << ansG << endl;
}