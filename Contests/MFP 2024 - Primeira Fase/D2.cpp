#include <bits/stdc++.h>
using namespace std;
static const long long NEG_INF = LLONG_MIN/4;

int N, K;
vector<vector<int>> adj;
vector<long long> xval;    // xval[i] = value for node i, for i=2..N.  We set xval[1]=0.
vector<int> parent_of;     // parent_of[i] = parent of i (i >= 2)
vector<int> tin, tout, order;
//   tin[v]  = DFS‐time when we enter v
//   tout[v] = DFS‐time when we finish v’s subtree
//   order[t] = which node has DFS‐time = t
int timer; 

void dfs(int v,int p){
    tin[v] = ++timer;
    order[timer] = v;
    for(int w: adj[v]){
        if(w==p) continue;
        dfs(w, v);
    }
    tout[v] = timer;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    xval.assign(N+1, 0LL);
    parent_of.assign(N+1, 0);
    for(int i=2; i<=N; i++){
        long long x; 
        cin >> x; 
        xval[i] = x;    // read “value” of node i
    }
    adj.assign(N+1, {});
    for(int i=2; i<=N; i++){
        int p; 
        cin >> p;
        parent_of[i] = p;
        adj[p].push_back(i);
        adj[i].push_back(p);
    }

    // 1) Run a DFS from node 1 to compute tin/tout and “order”.
    tin.assign(N+1,0);
    tout.assign(N+1,0);
    order.assign(N+1,0);
    timer = 0;
    dfs(1, 0);

    // 2) Build valueAtPos[s] = the "value" of the node whose DFS time = s.
    //    If s corresponds to v=1 (the root), we set valueAtPos[s]=NEG_INF so we never pick root.
    vector<long long> valueAtPos(N+2, 0LL);
    for(int s=1; s<=N; s++){
        int v = order[s];
        if(v==1) {
            valueAtPos[s] = NEG_INF; 
        } else {
            valueAtPos[s] = xval[v];
        }
    }

    // 3) We will build two arrays dp_prev[1..N+1], dp_cur[1..N+1], both length N+2 just to
    //    be safe with indexing at (N+1).  We will “roll” them for k=0..K.
    vector<long long> dp_prev(N+2, NEG_INF), dp_cur(N+2, NEG_INF);

    // Base case for k=0: dp(s,0)=0 for all s.  That is, "no picks => sum=0."
    for(int s=1; s<=N+1; s++){
        dp_prev[s] = 0LL;
    }

    // 4) Now fill layers k = 1..K in increasing order:
    for(int k=1; k<=K; k++){
        // By convention: dp(N+1, k) = -INF if k>0, because there are no indices >= N+1 except (N+1)
        dp_cur[N+1] = NEG_INF;

        // Fill s = N down to 1
        for(int s=N; s>=1; s--){
            // Option 1: skip position s
            long long bestSkip = dp_cur[s+1];

            // Option 2: take position s
            int v = order[s]; 
            int jump_to = tout[v] + 1;  
            long long bestTake;
            if(jump_to > N){
                // That means tout[v] = N, so jump_to = N+1
                // We consult dp_prev[N+1], which is (k-1==0?0 : -INF).
                bestTake = dp_prev[N+1] + valueAtPos[s];
            } else {
                bestTake = dp_prev[jump_to] + valueAtPos[s];
            }

            dp_cur[s] = max(bestSkip, bestTake);
        }

        // Now “dp_cur[s]” is fully computed = dp(s, k).  Copy it into dp_prev so that
        // next iteration (k+1) sees dp_prev = dp(.,k).
        dp_prev.swap(dp_cur);
    }

    // After finishing k=K, dp_prev[s] = dp(s,K) for all s.
    long long answer = dp_prev[1];
    if(answer < 0) answer = 0;   // if it stayed at NEG_INF or < 0, print 0 by problem statement
    cout << answer << "\n";
    return 0;
}
