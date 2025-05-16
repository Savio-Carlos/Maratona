#include <bits/stdc++.h>
using namespace std;

int main () {
    int t; cin >> t;
    while(t--){
        int n, k, d;
        cin >> n >> d >> k;
        vector<int> pfx(n+2,0);
        vector<int> vis(n+1,0);
        for (int i = 0; i < k; i++){
            int a, b;
            cin >> a >> b;
            int start = max(1,a-d+1);
            int end = b+1;
            
            pfx[start]++;
            if (end<=n) pfx[end]--; 
        }
        int cur = 0;
        for (int i = 1; i <= n-d+1; i++){
              cur += pfx[i];
              vis[i] = cur;
        }
        int mae ;
        int irmao;
        int mx = 0, mn = LLONG_MAX;

        for (int i = 1; i <= n-d+1; i++){
            if (vis[i] > mx) mx = vis[i], irmao = i;
            if (vis[i] < mn) mn = vis[i], mae = i;
        }
        cout << irmao << ' ' << mae << endl;
    }
}