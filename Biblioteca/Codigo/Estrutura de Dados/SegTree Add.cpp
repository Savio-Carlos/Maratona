//SegTree Add
//Adicao no intervalo
//Get o caminho 

tree[4*MAX];

void build(int node, int l, int r){
    if (l == r){
        tree[node] = 0;//alguma coisa
        return;
    }
    int m = (l+r)/2;
    build(node*2, l, m);
    build(node*2+1, m+1, r);
}

int get(int node, int l, int r, int i){
    if (l == r) return tree[node];
    int m = (l+r)/2;
    int res;
    if (i > m) res = get(node*2+1, m+1, r, i);
    else res = get(node*2, l, m, i); 
    return res + tree[node];
}

void add(int node, int l, int r, int a, int b, int x){
    if(b < l or r < a) return;
    if(a <= l && r <= b){
        tree[node] += x;
        return;
    }
    int m = (l+r)/2;
    add(2*node, l, m, a, b, x);
    add(2*node+1, m+1, r, a, b, x);
}

add(1,0,n-1, l, r, value)
get(1,0,n-1, index_of_search)