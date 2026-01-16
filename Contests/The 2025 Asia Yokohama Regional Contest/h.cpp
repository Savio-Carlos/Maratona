#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()


void dbg_out() {cerr << endl;}
template<typename H, typename... T>
void dbg_out(H h, T... t) {cerr << ' ' << h; dbg_out(t...);}

#define DEBUG

#if defined(DEBUG)
    #define fastio (void)0
    #define debug(...) cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__);
#else 
    #define fastio ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL)
    #define debug(...) (void)0
#endif


const int MAXN = 1e3+7;
int n, m, k;
char grid[MAXN][MAXN];
int visited[MAXN][MAXN];
map<char, int> mpy = {
    {'U', 0},
    {'D', 0},
    {'L', -1},
    {'R', 1}
};

map<char, int> mpx = {
    {'U', -1},
    {'D', 1},
    {'L', 0},
    {'R', 0}
};

map<char, char> op = {
    {'U', 'D'},
    {'D', 'U'},
    {'L', 'R'},
    {'R', 'L'}
};


vector<pair<char, char>> v = {
    {'R', 'D'},
    {'R', 'U'},
    {'L', 'D'},
    {'L', 'U'},
    {'D', 'R'}, 
    {'D', 'L'},
    {'U', 'R'},
    {'U', 'L'},
    {'U', 'U'}, 
    {'D', 'D'}
};

bool faz(int dx, int dy){
    if(dx < 0 || dx >= n) return false;
    if(dy < 0 || dy >= m) return false;
    if(grid[dx][dy] != '#') return false;
    return true;
}

tuple<int, int, int> borda(int x, int y, char p){
    int cnt = 1;
    int dx = x, dy = y;
    while(cnt < k){
        dx = mpx[p] + dx;
        dy = mpy[p] + dy;
        if(faz) cnt++;
    }
    return {cnt, dx, dy};
}

bool direcao(int x, int y, char dir1, char dir2){
    int dx = x, dy = y;
    int cnt = 1;
    vector<pair<int, int>> pos;
    pos.push_back({x, y});
    for(int i = 1; i < k; i++){
        dx = dx + mpx[dir1];
        dy = dy + mpy[dir1];
        //cout << dx << " " << dy << " " << grid[dx][dy] << endl;
        if(faz(dx, dy)){
            //cout << dx << " " << dy << endl;
            cnt++;
            pos.push_back({dx, dy});
        }
        //cout << dx << " " << dy << endl;
    }
    if(cnt < k) return false;
    for(int i = 1; i < k; i++){
        dx = dx + mpx[dir2];
        dy = dy + mpy[dir2];
        //cout << dx << " " << dy << " " << grid[dx][dy] << endl;
        if(faz(dx, dy)){
            //cout << dx << " " << dy << endl;
            cnt++;
            pos.push_back({dx, dy});
        }
        //cout << dx << " " << dy << endl;
    }
    if(cnt == 2*k - 1){
        for(auto [a, b] : pos){
            cout << a << " " << b << endl;
            visited[a][b] = 1;
        }
        return true;
    }
    return false;
}

void marcar(int e1, int e2, char p){
    visited[e1][e2] = 1;
    int dx = e1, dy = e2;
    for(int i = 0; i < k; i++){
        dx = dx + mpx[p];
        dy = dy + mpy[p];
        visited[dx][dy] = 1;
    }
}

bool func(int x, int y, char p){
    //como checar se todos os 3 sao validos?
    //olhando se existe essa borda p qualquer borda
    auto [cnt, ea, eb] = borda(x, y, p);
    auto [cnt1, ec, ed] = borda(ea, eb, op[p]);
    //cout << cnt1 << endl;
    if(cnt1 != k) return false;
    //cout << "passou desse\n";
    vector<pair<int, int>> endpoints;
    endpoints.push_back({ea, eb});
    endpoints.push_back({ec, ed});
    for(auto [ep1, ep2] : endpoints){
        //cout << ep1 << " " << ep2 << endl;
        for(int i = 0; i < 8; i++){
            auto [dir1, dir2] = v[i];
            if(dir1 == p || dir1 == op[p]) continue;
            //cout << ep1 << " " << ep2 << " " << dir1 << " " << dir2 << endl;
            if(direcao(ep1, ep2, dir1, dir2)){
                cout << ep1 << " " << ep2 << " " << dir1 << " " << dir2 << endl << endl;
                marcar(ea, eb, p);
                return true;
            }
        }
    }

    vector<pair<int, int>> pos;
    for(int i = 8; i < 10; i++){
        int dx = ea, dy = eb;
        int nx = ec, ny = ed;
        for(int j = 0; j < k; j++){
            dx = dx + mpx[v[i].first];
            dy = dy + mpy[v[i].first];
            nx = nx + mpx[v[i].first];
            ny = ny + mpy[v[i].first];
            if(faz(dx, dy)){
                cnt++;
                pos.push_back({dx, dy});
            }
            if(faz(nx, ny)){
                cnt++;
                pos.push_back({nx, ny});
            }
        }
    }
    
    if(cnt == 3*k){
        for(auto [a, b] : pos){
            visited[a][b] = 1;
        }
        return true;
    }
    return false;
}

signed main(){
    fastio;
    int t; cin >> t;
    while(t--){
        cin >> n >> m >> k;
        int cnt = 0, cnt2 = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> grid[i][j];
                if(grid[i][j] == '#') cnt++;
            }
        }
        //direcao(7, 2, 'R', 'U');
        //func(3, 2, 'D');
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '#' && !visited[i][j]){
                    for(auto [dir, _] : op){
                        int dx = i + mpx[dir];
                        int dy = j + mpx[dir];
                        //cout << i << " " << j << " " << dx << " " << dy << endl;
                        if(faz(dx, dy) && func(dx, dy, dir))break;
                    }
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << visited[i][j] << " ";
                if(grid[i][j] == '#' && visited[i][j]) cnt2++;
            }
            cout << endl;
        }

        // if(cnt != cnt2) cout << "no\n";
        // else cout << "yes\n";
    }
}