 #include <bits/stdc++.h>
#define int long long
#define ld long double
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

signed main(){
    fastio;
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> ans(m+1, 0);
    map<int,int> last;
    while (k--){
        int c, t;
        cin >> t >> c;
        if (last.find(c) != last.end()){
            if (last[c] == -1){//nova entrada
                last[c] = t;
            }
            else {
                if (abs(t - last[c]) == 0) ans[c] += 100;
                else ans[c] += abs(t - last[c]);
                last[c] = -1;
            }
        }
        else {
            last[c] = t;
        }
    }
    for (auto [i,w] : last){
        if (w != -1) ans[i] += 100;
    }
    for (int i = 1; i <= m; i++){
        cout << ans[i] << " "; 
    }
    cout << endl;
}