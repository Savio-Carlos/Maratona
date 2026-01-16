#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()


void dbg_out() {cerr << endl;}
template<typename H, typename... T>
void dbg_out(H h, T... t) {cerr << ' ' << h; dbg_out(t...);}

#define DEBUG

#if defined(DEBUG)
    #define fastio (void)0
    #define debug(...) cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__);
#else 
    #define fastio ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL)
    #define debug(...) (void)0
#endif

int qnt(ld x, ld y, ld z, ld val){
    return (x / val) + (y / val) + (z / val);
}

bool valid(ld x, ld y, ld z, ld val, int k){
    return qnt(x, y, z, val) >= k;
}

signed main(){
    // fastio;
    int t;
    cin >> t;
    while(t--){
        vector<ld> v(3);
        for(int i = 0; i < 3; i++){
            cin >> v[i];
        }
        int k;
        cin >> k;
        pair<int,int> ans;
        int debug = 0;

        double esq = 1e9, dir = 1e9;
        while(esq != 0){
            double meio = dir / esq;
            if(valid(v[0], v[1], v[2], meio, k)){
                ans = {esq, dir};
                dir = meio;
            } else {
                esq = meio;
            }
            cout << esq << " " << dir << " " << meio << endl;
            debug++;
            // if(debug == 20) return 0;
        }
        cout << "ans = " << ans.first << " " << ans.second << endl;
    }
}