#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAX = 5e4+7;

signed main(){
    winton;
    int n, m, p, s;
    int ans = 0;
    cin >> n >> m >> p >> s;
    s+=p;
    vector<pair<int,int>> pares(m);
    for (int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        pares[i] = {a-1,b-1};
    }
    for (int i = 0; i < (1<<n); i++){
        int paocnt = 0, salcnt = 0;
        bool pos = true;
        vector<int> cur;
        for (int j = 0; j < p; j++){
            int pos = (1<<j);
            if (i&pos){
                paocnt++;
                cur.push_back(j);
            }
        }
        if (paocnt != 1) continue;
        for (int j = p; j < s; j++){
            int pos = (1<<j);
            if (i&pos){
                salcnt++;
                cur.push_back(j);
            }
        }
        if (salcnt != 1) continue;
        for (int j = s; j < n; j++){
            int pos = (1<<j);
            if (i&pos){
                cur.push_back(j);
            }
        }
        for (auto [a,b] : pares){
            int pos1 = (1<<a);
            int pos2 = (1<<b);
            if (pos1&i && pos2&i) {
                pos = false;
                continue;
            }
        }

        if (pos) {
            //for (auto u : cur) cout << u << " ";
            ans++;
        }
       // cout << endl;
    }
    cout << ans << endl;
}