# binclude <bits/stdc++.h>
using namespace std;

int n, s, mx, my, ex, ey;
const int MAXN = 807;
char grid[MAXN][MAXN];
int bees[MAXN][MAXN];
int mecho[MAXN][MAXN];
int visited[MAXN][MAXN];
int d1[] = {0, 1, 0, -1};
int d2[] = {1, 0, -1, 0};

bool valid(int dx, int dy){
    return dx >= 0 && dx < n && dy >= 0 && dy < n && (grid[dx][dy] == 'G' || grid[dx][dy] == 'M');
}

bool chega(int m, int b){
    return ((m/s) < b);
}

bool check(int d){

    if(bees[mx][my] <= d) return false;

    queue<pair<int, int>> pq;
    pq.push({mx, my});

    //reset
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            visited[i][j] = 0;
            mecho[i][j] = 0;
        }
    }
    
    visited[mx][my] = 1;
    while(!pq.empty()){
        auto [i, j] = pq.front(); pq.pop();
        for(int x = 0; x < 4; x++){
            int dx = d1[x] + i;
            int dy = d2[x] + j;
            if(valid(dx, dy) && !visited[dx][dy] && chega(mecho[i][j] + 1, bees[dx][dy] - d)){
                mecho[dx][dy] = mecho[i][j] + 1;
                visited[dx][dy] = 1;
                pq.push({dx, dy});
            }
        }
    }


    // cout << "mecho here" << endl;
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         cout << mecho[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    bool res = false;
    for(int i = 0; i < 4; i++){
        int dx = d1[i] + ex;
        int dy = d2[i] + ey;
        if(valid(dx, dy) && chega(mecho[dx][dy], bees[dx][dy]) && visited[dx][dy]){
            res = true;
        }
    }
    return res;
}

int main(){
    cin >> n >> s;
    vector<pair<int, int>> h;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'H')
                h.push_back({i, j});
            else if(grid[i][j] == 'M'){
                mx = i;
                my = j;
            }else if(grid[i][j] == 'D'){
                ex = i;
                ey = j;
            }

        }
    }

     //bfs para bees
    //t, i, j
    queue<pair<int, int>> pq;
    for(auto u : h)  pq.push({u.first, u.second});
    
    //funcionando o bfs para as abelhas!!
    while(!pq.empty()){
        auto [i, j] = pq.front();
        pq.pop();
        for(int x = 0; x < 4; x++){
            int dx = d1[x] + i;
            int dy = d2[x] + j;
            if(valid(dx, dy) && !bees[dx][dy]){
                bees[dx][dy] = bees[i][j] + 1;
                pq.push({dx, dy});
            }
        }
    }


    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         cout << bees[i][j] << " ";
    //     }
    //     cout << endl;
    // }


    int l = 0, r = n*n; 
    while(l <= r){
        //cout << l << " " << r << endl;
        int mid = (l+r)/2;
        if(check(mid)) l = mid+1;
        else r = mid-1;
    }

    cout << l-1 << endl;

}