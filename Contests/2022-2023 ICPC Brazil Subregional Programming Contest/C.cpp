#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAX = 2e3+14;

int grid[MAX][MAX], visited[MAX][MAX];
map<int,int> sizes;
vector<pair<int,int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int mxx = 0, mxy = 0;

bool valid(int x, int y){
    return (x>=0 && x<=mxx && y>=0 && y<=mxy);
}

void floodfill(int i, int j, int c){
    queue<pair<int,int>> q;
    q.push({i,j});
    visited[i][j] = 1;
    if (i%2 && j%2) sizes[c]++;
    while(!q.empty()){
        auto [curx, cury] = q.front();
        q.pop();
        
        for (auto [nx, ny] : moves){
            if (valid(curx+nx, cury+ny) && !visited[curx+nx][cury+ny] && grid[curx+nx][cury+ny] == 0){
                visited[curx+nx][cury+ny] = 1;
                q.push({curx+nx, cury+ny});
                if ((curx+nx)%2 && (cury+ny)%2) sizes[c]++;
            }
        }
    }
}

signed main(){
    winton;
    int n;
    cin >> n;
    vector<pair<int,int>> cuts(n+1);
    for (auto &[u,i] : cuts) cin >> u >> i;
    for (int i = 0; i < n; i++){
        auto [x1, y1] = cuts[i];
        auto [x2, y2] = cuts[i+1];

        int xi, xf, yi, yf;
        xi = 2*(min(x1, x2));
        xf = 2*(max(x1, x2));
        yi = 2*(min(y1, y2));
        yf = 2*(max(y1, y2));
        mxy = max(mxy,yf);
        mxx = max(mxx,xf);

        if(yi == yf){       
            while (xi <= xf){
                grid[xi][yi] = -1;
                visited[xi][yi] = 1;
                xi++;
            }
        }
        else {
            while (yi <= yf){
                grid[xi][yi] = -1;
                visited[xi][yi] = 1;
                yi++;
            }
        }
    }
    mxx += 2;
    mxy += 2;   
    int c = 1;
    for (int i = 0; i <= mxx; i++){
        for (int j = 0; j <= mxy; j++){
            if (!visited[i][j] && grid[i][j] == 0){
                floodfill(i,j, c);
                c++;
            }
        }
    }
    // for (int i = 0; i <= mxx; i++){
    //     for (int j = 0; j <= mxy; j++){
    //         if (grid[i][j] == -1) cout << "#" << " ";
    //         else cout << grid[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    //cout << "MAXIMOS: " << mxx <<" "<< mxy << endl;
    int ans = 0;
    sizes.erase(1);
    for (auto u : sizes) {
        ans = max(u.second,ans);
        //cout << u.first << " " << u.second << endl;
    }
    cout << ans << endl;
}