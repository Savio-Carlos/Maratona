// Disjoint Set Union (Union-Find)
// O(α(N)) - quase constante

// find: O(log(N)) amortizado
// unite: O(log(N)) amortizado

ll find(ll x){
    if (parent[x]<0)return x;
    return parent[x]=find(parent[x]);
}

void unite(ll x,ll y){
    ll a=find(x),b=find(y);
    if(a==b)return;
    if(parent[a]<=parent[b]){
        parent[a]+=parent[b];
        parent[b]=a;
    }else{
        parent[b]+=parent[a];
        parent[a]=b;
    }
};