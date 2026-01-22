#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'

#define winton ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

struct BIT{
    vector<int> bit;
    int n;
    void init(int _n){
        n = _n;
        bit.assign(n+1, 0);
    }
 
    int sum(int x){
        int s = 0;
        for(; x > 0; x -= x&(-x)){
            s += bit[x];
        }
        return s;
    }
 
    void upd(int x, int v){
        for(; x <= n; x += x&(-x)){
            bit[x] += v;
        }
    }
};

int n;

struct intervalo {
    long long l, r;
    int id;
};

int main() {
    winton;
    while(cin >> n) {
        vector<intervalo> intervalos(n);
        vector<int> points;
        for(int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            intervalos[i] = {a, b, i};
            points.push_back(a);
            points.push_back(b);
        }

        sort(all(points));
        points.erase(unique(all(points)), points.end());
        
        auto getidx = [&](int x) {
            return lower_bound(all(points), x) - points.begin() + 1;
        };
        
        int m = points.size();
        
        vector<vector<int>> ends(m + 1);
        for(int i = 0; i < n; i++) {
            int r = getidx(intervalos[i].r);
            ends[r].push_back(i);
        }
        
        BIT bit;
        bit.init(m);
        vector<int> ans(n);
        
        for(int r = m; r >= 1; r--) {
            if(ends[r].empty()) continue;

            sort(all(ends[r]), [&](int i, int j) {
                return intervalos[i].l < intervalos[j].l;
            });
            
            int sz = ends[r].size();
            int k = 0;
            while(k < sz) {
                int start = k;
                int cl = intervalos[ends[r][k]].l;

                while(k < sz && intervalos[ends[r][k]].l == cl) {
                    k++;
                }
                
                int ll = getidx(cl);
                int cnt = bit.sum(ll);
                
                for(int i = start; i < k; i++) ans[intervalos[ends[r][i]].id] = cnt;
                
                bit.upd(ll, k - start);
            }
        }
        
        for(auto u : ans) cout << u << " ";
        cout << endl;
    }
}

