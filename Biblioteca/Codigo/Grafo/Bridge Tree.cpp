//Bridge Tree
// Acha as bridges do grafo e monta a bridge tree

int t, c, low[MAX], pre[MAX], visited[MAX], comp[MAX];
stack<int> st;
vector<int> graph[MAX], compgraph[MAX];

void dfs(int v, int p){
    visited[v] = 1;
    low[v] = pre[v] = ++t;
    st.emplace(v);
    for (auto u : graph[v]){
        if (!visited[u]){
            dfs(u,v);
            low[v] = min(low[v], low[u]);
        }   
        else {
            if (u == p) continue;
            low[v] = min(low[v], pre[u]);
        }
    }
    if (low[v] == pre[v]){ //achamos uma bridge
        c++;
        int cur;
        do {
            cur = st.top();
            st.pop();
            comp[cur] = c;
            compgraph[c].push_back(cur);
        } while(cur != v);
    }
}