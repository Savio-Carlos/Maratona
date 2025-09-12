// Kosaraju
// O(V + E)

// dfs: O(V + E)
// dfs2: O(V + E)
// compresstree: O(V + E)

vector<ll>graph[inf],reverso[inf],visited(inf,0),comp(inf,0),outorder;
 
void dfs(ll node){
    visited[node]=1;
    for (auto next:graph[node]){
        if (!visited[next])dfs(next);
    }
    outorder.push_back(node);
 
}
 
void dfs2(ll node, ll c){
    visited[node]=2;
    comp[node]=c;
    for (auto next:reverso[node]){
        if (visited[next]==1)dfs2(next,c);
    }   
}
 
unordered_set<ll>dag[inf];
vector<ll>outdeg(inf,0);
vector<ll>indeg(inf,0);

void compresstree(ll n, ll c){
    for (ll i = 1; i <=n; i++){
        for(auto u:graph[i]){
            if (comp[i]!=comp[u]){
                auto res = dag[comp[i]].insert(comp[u]);
                if (res.second) {
                    outdeg[comp[i]]++;
                    indeg[comp[u]]++;
                }
            }
        }
    }
    
}