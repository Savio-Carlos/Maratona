#include <bits/stdc++.h>
using namespace std;

static const int MAXN = 100;
int N, M;
vector<vector<int>> movie_actors;
vector<vector<int>> actor_movies;

// movie–movie bitset adjacency, and for each (i,j) which actor caused it
bitset<MAXN+1> adj[MAXN+1];
int actor_shared[MAXN+1][MAXN+1];

// BFS tables
bitset<MAXN+1> visited[MAXN+1];
int parent_movie[MAXN+1][MAXN+1];
int via_actor[MAXN+1][MAXN+1];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    movie_actors.resize(N+1);
    actor_movies.resize(M+1);

    // 1) Read input, build actor_movies
    for(int i = 1; i <= N; i++){
        int ni; 
        cin >> ni;
        movie_actors[i].resize(ni);
        for(int j = 0; j < ni; j++){
            int a; 
            cin >> a;
            movie_actors[i][j] = a;
            actor_movies[a].push_back(i);
        }
    }

    // 2) Build movie–movie bitset adj + record one actor_shared[i][j]
    for(int a = 1; a <= M; a++){
        auto &L = actor_movies[a];
        for(int i = 0; i < (int)L.size(); ++i){
            for(int j = i+1; j < (int)L.size(); ++j){
                int u = L[i], v = L[j];
                if (!adj[u].test(v)) {
                    adj[u].set(v);
                    adj[v].set(u);
                    actor_shared[u][v] = actor_shared[v][u] = a;
                }
            }
        }
    }

    // 3) BFS from each movie s
    for(int s = 1; s <= N; s++){
        visited[s].reset();
        for(int v = 1; v <= N; v++){
            parent_movie[s][v] = -2;
            via_actor[s][v] = -1;
        }

        queue<int> q;
        visited[s].set(s);
        parent_movie[s][s] = -1;
        q.push(s);

        while(!q.empty()){
            int u = q.front(); 
            q.pop();
            // get the new neighbors in one bitset op
            auto nbrs = adj[u] & (~visited[s]);
            while(nbrs.any()){
                int v = nbrs._Find_first();
                nbrs.reset(v);
                visited[s].set(v);
                parent_movie[s][v] = u;
                via_actor[s][v]    = actor_shared[u][v];
                q.push(v);
            }
        }
    }

    // 4) Answer queries
    int Q; 
    cin >> Q;
    vector<char> mark(N+1, 0);
    while(Q--){
        int x,y; 
        cin >> x >> y;
        auto &Sx = actor_movies[x];
        auto &Sy = actor_movies[y];

        // common movie?
        bool done = false;
        for(int m:Sx) mark[m]=1;
        for(int m:Sy) if(mark[m]){
            cout << 2 << "\n" << x<<" "<<m<<" "<<y<<"\n";
            done = true;
            break;
        }
        for(int m:Sx) mark[m]=0;
        if(done) continue;

        // otherwise find any reachable (s in Sx)->(t in Sy)
        int rs=-1, rt=-1;
        for(int s:Sx){
            for(int t:Sy){
                if(parent_movie[s][t]>=-1){
                    rs=s; rt=t;
                    break;
                }
            }
            if(rs!=-1) break;
        }
        if(rs<0){
            cout << "-1\n";
            continue;
        }

        // reconstruct movie path from rs to rt
        vector<int> movep;
        for(int cur=rt; cur!=rs; cur=parent_movie[rs][cur])
            movep.push_back(cur);
        movep.push_back(rs);
        reverse(movep.begin(), movep.end());

        int L = movep.size();
        cout << (L+1) << "\n";
        cout << x;
        for(int i=0;i<L;i++){
            cout << " " << movep[i];
            if(i+1<L)
                cout << " " << via_actor[rs][ movep[i+1] ];
            else
                cout << " " << y;
        }
        cout<<"\n";
    }
    return 0;
}