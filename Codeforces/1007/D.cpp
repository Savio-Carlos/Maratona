#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long
#define ld long double
const int MAXL = 1e9+7;

signed main() {_ 
    int t;
    cin >> t;
    while (t--){
        int n, l, r;
        cin >> n >> l >> r;
        vector<int> seq(n), pfx(n);
        for (int i = 0; i < n; i++){
            cin >> seq[i];
        }
        pfx[0] = seq[0];

        for (int i = 1; i < n; i++){
            pfx[i] = seq[i];
            pfx[i] ^= pfx[i-1];
        }

        vector<int> nxt;
        if (l > n){
            nxt.resize((l-n) + 1);
            vector<int> pfxnxt(l-n+1);
            for (int i = 0; i < (l-n) + 1; i++){
                if (i < n){
                    nxt[i] = pfxnxt[i/2];
                }
                else {
                    nxt[i] = nxt[i/2];
                }
                if (i > 0) pfxnxt[i] = nxt[i] ^ pfxnxt[i-1];
            }
        }
        
        if (l > n){
            cout << nxt[(l-n)/2] << endl;
        }
        else {
            cout << pfx[l] << endl;
        }
    }
}