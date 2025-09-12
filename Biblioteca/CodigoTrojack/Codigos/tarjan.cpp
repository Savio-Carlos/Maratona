// Componentes Biconexas e Árvore de Blocos e Cortes
// O(V + E)

// dfs: O(V + E)
// newBiconectedComponent: O(E) em total
// makeblockcuttree: O(V + E)

vector<pair<ll,ll>>graph[inf];
vector<ll>low(inf,0),pre(inf,0),visited(inf,0),visitededge(inf,0);
stack<ll>edgeStack;
ll t,c,p=-1,d;

vector<ll>articul(inf,0);
vector<ll>edgecomponent(inf,0);

void newBiconectedComponent(ll idAresta){
    c++;
    ll a;
    do{
        a=edgeStack.top();
        edgeStack.pop();
        p--;
        edgecomponent[a]=c;
        if(p==-1)break;
    } while (a!=idAresta);
}

void dfs(ll node, ll pai){
    t++;
    pre[node]=t;
    low[node]=t;
    visited[node]=1;
    ll filhos=0;
    for(auto [next,idAresta]:graph[node]){
        if(visitededge[idAresta]==1)continue;
        visitededge[idAresta]=1;
        p++;
        edgeStack.push(idAresta);

        if(!visited[next]){
            filhos++;
            dfs(next,node);
            low[node]=min(low[node],low[next]);

            bool newComponent = false;
            if(node==1 && filhos>=2) newComponent=true;
            if(node!=1 && low[next]>=pre[node]) newComponent=true;

            if(newComponent){
                articul[node]=1;
                newBiconectedComponent(idAresta);
            }
        }else{
            low[node]=min(low[node],low[next]);
        }
    }
}

vector<ll>blockcuttree[inf],marcComp(inf,0),articulId(inf,0);

void makeblockcuttree(ll n){
    for (ll i = 1; i <= n; i++){
        if(articul[i] != 1) continue;

        c++;
        articulId[i] = c;

        for (auto [next, idAresta] : graph[i]){
            ll comp = edgecomponent[idAresta];
            if(!marcComp[comp]){
                marcComp[comp] = 1;
                blockcuttree[articulId[i]].push_back(comp);
                blockcuttree[comp].push_back(articulId[i]);
            }
        }

        for (auto [next, idAresta] : graph[i]){
            ll comp = edgecomponent[idAresta];
            marcComp[comp] = 0;
        }
    }
}

