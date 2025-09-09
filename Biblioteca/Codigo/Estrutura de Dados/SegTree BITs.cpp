//SegTree Bits
/*
si = vetor se diz se aquela posicao esta valida/funcionanando
on = arvore que conta quantos estao ligados
valid = arvore que conta quantos sao validos naquele intervalo (exclusivo de um problema la)
toda operacao ele calcula os ligados com base em quantos tem valido naquele intervalo - os desligados, ja que ta sempre invertendo
*/
int n, tree[4*MAX], on[4*MAX], valid[4*MAX], si[MAX];
bool lazy[4*MAX];

void build(int node, int l, int r){
    lazy[node] = false;
    if (l == r){
        if (si[l] == -1){
            on[node] = 0;
            valid[node] = 0;
        }
        else{
            valid[node] = 1;
            on[node] = si[l];
        }
        return;
    }
    int m = (l+r)/2;
    build(node*2, l, m);
    build(node*2+1, m+1, r);
    valid[node] = valid[node*2] + valid[node*2+1];
    on[node] = on[node*2] + on[node*2+1];
}
void flip(int node){
    on[node] = valid[node] - on[node];
    lazy[node] = !lazy[node];
}

void prop(int node){
    if (lazy[node]){
        flip(node*2);
        flip(node*2+1);
        lazy[node] = false;
    }
}

void update(int node, int l, int r, int a, int b){
    if(b < l or r < a) return;
    if(a <= l && r <= b){
        flip(node);
        return;
    }
    prop(node);
    int m = (l+r)/2;
    update(2*node, l, m, a, b);
    update(2*node+1, m+1, r, a, b);
    on[node] = on[node*2] + on[node*2+1];
}