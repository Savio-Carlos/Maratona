#include <bits/stdc++.h>

#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define int long long

using namespace std;

struct BIT {
    int n;
    vector<int> bit;
    void init(int _n){
        n = _n+1;
        bit.resize(n+1, 0);
    }

    void upd(int x, int v){
        x++;
        for(; x <= n; x+=x&(-x)) bit[x] += v;
    }

    int sum(int x){
        int s = 0;
        x++;
        for(; x > 0; x -= x&(-x)) s += bit[x];
        return s;
    }

    int query(int l, int r){
        return sum(r) - sum(l-1);
    }
};

vector<int> pos;
int offset = 0;
int k;
BIT bit;


int soma(int l, int r){
    int pl = (offset + l)%k;
    int pr = (offset + r)%k;
    if(pl <= pr) return bit.query(pl, pr);
    else{
        return bit.query(pl, k-1) + bit.query(0, pr);
    }
}

signed main(){
    fastio;
    int q; cin >> q >> k;
    pos.resize(k);
    bit.init(k);
    int sum = 0;
    for(int i = 0; i < k; i++){
        pos[i] = i;
        bit.upd(i, i);
        sum += i;
    }

    
    while(q--){
        int op; cin >> op;
        op--;
        if(!op){
            int p; cin >> p;
            offset = (offset + p)%k;
        }else if(op == 1){
            int s, t; cin >> s >> t;
            int ps = (offset + s)%k;
            int pt = (offset + t)%k;
            int vs = pos[ps];
            int vt = pos[pt];

            swap(pos[ps], pos[pt]);

            bit.upd(ps, vt - vs);
            bit.upd(pt, vs - vt);
        }else{
            int l, r; cin >> l >> r;

            int bst = l/k;
            int bend = r/k;
            int idxs = l%k;
            int idxe = r%k;
            int tot = 0;
            //tudo no msm bloco
            if(bst == bend){
                int s = soma(idxs, idxe);
                int cnt = (idxe - idxs + 1);
                tot += s + (cnt*bst*k);
            }else{
                //sufixo do 1 bloco
                int s = soma(idxs, k-1);
                int cnts = (k- idxs);
                tot += s + (cnts*bst*k);

                //prefixo do ultimo bloco
                int p = soma(0, idxe);
                tot += p + ((idxe+1)*bend*k);

                if(bend > bst + 1){
                    int amnt = bend - bst - 1;
                    tot += (amnt*sum);
                    int sind = (bend + bst)*amnt/2;
                    tot += sind*k*k;
                }
            }
            cout << tot << endl;
        }
    }
}
 