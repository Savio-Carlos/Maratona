#include <bits/stdc++.h>
using namespace std;

int solve_bfs(int n, vector<int> a, vector<int> p) {
    int k = p.size();
    int x = a[p[0]];
    int target = 0; // all bits x

    int start_mask = 0;
    for(int i=0; i<n; ++i) {
        if(a[i] != x) start_mask |= (1<<i);
    }

    queue<int> q;
    vector<int> dist(1<<n, -1);
    
    q.push(start_mask);
    dist[start_mask] = 0;

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        if(u == 0) return dist[u];

        for(int l=0; l<n; ++l) {
            for(int r=l; r<n; ++r) {
                // check if covers special
                bool ok = false;
                for(int sp : p) {
                    if(l <= sp && sp <= r) {
                        ok = true;
                        break;
                    }
                }
                if(ok) {
                    int v = u;
                    for(int i=l; i<=r; ++i) v ^= (1<<i);
                    if(dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        q.push(v);
                    }
                }
            }
        }
    }
    return -1;
}

int solve_math(int n, vector<int> a, vector<int> p) {
    int k = p.size();
    int x = a[p[0]];
    vector<int> b(n+2, 0);
    for(int i=0; i<n; ++i) b[i+1] = (a[i] == x ? 0 : 1);
    
    vector<int> c(n+2, 0);
    int S = 0;
    for(int i=1; i<=n+1; ++i) {
        c[i] = b[i] ^ b[i-1];
        if(c[i]) S++;
    }
    
    vector<int> I(n+2, 0);
    int cur_p = 0;
    for(int i=1; i<=n+1; ++i) {
        if(cur_p < k && i > p[cur_p]+1) {
            cur_p++;
        }
        I[i] = cur_p;
    }
    
    vector<int> C(k+1, 0);
    for(int i=1; i<=n+1; ++i) {
        if(c[i]) C[I[i]]++;
    }
    
    int M = 0;
    for(int count : C) M = max(M, count);
    
    return max(S/2, M);
}

int main() {
    srand(123);
    for(int n=1; n<=10; ++n) {
        for(int k=1; k<=n; ++k) {
            for(int iter=0; iter<100; ++iter) {
                vector<int> p_pool;
                for(int i=0; i<n; ++i) p_pool.push_back(i);
                random_shuffle(p_pool.begin(), p_pool.end());
                vector<int> p;
                for(int i=0; i<k; ++i) p.push_back(p_pool[i]);
                sort(p.begin(), p.end());

                vector<int> a(n);
                for(int i=0; i<n; ++i) a[i] = rand()%2;
                
                int x = rand()%2;
                for(int sp : p) a[sp] = x;

                int ans1 = solve_bfs(n, a, p);
                int ans2 = solve_math(n, a, p);
                
                if(ans1 != ans2) {
                    cout << "FAIL! " << "n=" << n << " k=" << k << " a=";
                    for(int v : a) cout << v;
                    cout << " p=";
                    for(int sp : p) cout << sp;
                    cout << " ans1=" << ans1 << " ans2=" << ans2 << "\n";
                    return 0;
                }
            }
        }
    }
    cout << "ALL OK!\n";
    return 0;
}
