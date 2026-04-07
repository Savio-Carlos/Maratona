#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define int long long
#define ld long double
#define winton ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

signed main(){
    winton;
    int n, k;
    cin >> n >> k;
    vector<string> base(n);
    for(auto &s : base) cin >> s;
    vector<string> cur = base;
    
    for(int kk = 2; kk <= k; kk++){
        int sz = cur.size();
        int nsz = sz * n;
        vector<string> nxt(nsz, string(nsz, '.'));
        
        for(int i = 0; i < sz; i++){
            for(int j = 0; j < sz; j++){
                if(cur[i][j] == '#'){
                    for(int ni = 0; ni < n; ni++){
                        for(int nj = 0; nj < n; nj++){
                            nxt[i*n+ni][j*n+nj] = base[ni][nj];
                        }
                    }
                }
            }
        }
        cur = nxt;
    }
    for(auto s : cur) cout << s << endl;
}