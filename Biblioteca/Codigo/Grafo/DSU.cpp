//DSU 

struct DSU{
    int n;
    vector<int> p, r;
    void init(int _n){
        n = _n;
        p.resize(n);
        r.resize(n);
        for(int i = 0; i < n; i++){
            p[i] = i;
            r[i] = 0;
        }
    }

    int find(int x){
        return p[x] == x ? x : find(p[x]);
    }

    bool unite(int a, int b){
        a = find(a);
        b = find(b);
        if(a == b) return false;
        if(r[a] == r[b]) r[a]++;
        if(r[a] > r[b]){
            p[b] = a;
            r[a]++;
        }else{
            p[a] = b;
            r[b]++;
        }
        return true;
    }
}