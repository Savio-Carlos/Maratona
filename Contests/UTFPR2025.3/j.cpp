#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define int long long
#define ld long double

namespace dbg {
    const char* const RESET     = "\033[0m";
    const char* const BOLD_BLUE = "\033[1;34m";
    const char* const YELLOW    = "\033[33m";
    const char* const BOLD_WHITE= "\033[1;37m";

    template<typename T1, typename T2>
    ostream& operator<<(ostream& os, const pair<T1, T2>& p) { return os << '{' << p.first << ", " << p.second << '}'; }

    template<typename T_container, typename T = typename enable_if<!is_same_v<T_container, string> && !is_same_v<T_container, string_view>, typename T_container::value_type>::type>
    ostream& operator<<(ostream& os, const T_container& v) {
        os << '{';
        bool first = true;
        for (const T& x : v) { os << (first ? "" : ", ") << x, first = false; }
        return os << '}';
    }

    void debug_out(string_view) { cerr << endl; }
    template<typename H, typename... T>
    void debug_out(string_view s, H h, T... t) {
        auto cpos = s.find(',');
        cerr << YELLOW << s.substr(0, cpos) << RESET << " = ";
        cerr << BOLD_WHITE << h << RESET;
        if constexpr (sizeof...(t) > 0) {
            cerr << ", ";
            auto nx = s.find_first_not_of(" \t\n\r", cpos + 1);
            debug_out(s.substr(nx), t...);
        } else {
            cerr << endl;
        }
    }
} 
using namespace dbg;

// #define DEBUG

#if defined(DEBUG)
    #define winton (void)0
    #define debug(...) cerr << BOLD_BLUE << "[" << __func__ << ":" << __LINE__ << "]" << RESET << " "; debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
    #define winton ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
    #define debug(...) (void)0
#endif

const int MAX = 3e3+7;
const int INF = 1e18;

int n, m;
char grid[MAX][MAX];
int visited[MAX][MAX][4];
int dist[MAX][MAX][4];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, 1, -1, 0};

bool valid(int x, int y){
    return (x >= 0 && x < n && y >= 0 && y < m);
}

signed main(){
    winton;
    cin >> n >> m;
    pair<int,int> st, en;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> grid[i][j];
            if (grid[i][j] == 'E') st = {i,j};
            if (grid[i][j] == 'R') en = {i,j};
            dist[i][j][0] = dist[i][j][1] = dist[i][j][2] = dist[i][j][3] = INF;
        }
    }
    queue<tuple<int,int,int>> q;
    dist[st.first][st.second][0] = 0;
    q.push({st.first, st.second, 0LL});

    while(!q.empty()){
        auto [x,y,c] = q.front();
        q.pop();
        
        visited[x][y][c] = 1;
        debug(x,y,c);
        int cd = dist[x][y][c];//distancia para o estado atual
        char cur = grid[x][y];
        if (cur == '1' || cur == '2' || cur == '3'){//caso que eu encontro uma chave e posso aumentar o nivel
            if (cur == '1' && c == 0) c = 1;
            else if (cur == '2' && c == 1) c = 2;
            else if (cur == '3' && c == 2) c = 3;
            dist[x][y][c] = cd;
            visited[x][y][c] = 1;
        }

        for (int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (valid(nx,ny)){
                debug(nx,ny,c);
                char prox = grid[nx][ny];
                if (prox == '#') continue;

                if (prox == 'A' && c < 1) continue;
                if (prox == 'B' && c < 2) continue;
                if (prox == 'C' && c < 3) continue;

                if (visited[nx][ny][c]) continue;

                if (dist[nx][ny][c] > cd + 1){
                    dist[nx][ny][c] = cd + 1;
                    visited[nx][ny][c] = 1;
                    q.push({nx, ny, c});
                }
            }
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            debug(i,j,dist[i][j][0],dist[i][j][1],dist[i][j][2]);
        }
    }
    auto [a,b] = en;
    int ans = min({dist[a][b][0], dist[a][b][1], dist[a][b][2], dist[a][b][3]});
    if (ans == INF) cout << -1 << endl;
    else cout << ans << endl;
}