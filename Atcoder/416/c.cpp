#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
const int MAX = 2e5+7;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f3f3f3f3fLL;

vector<vector<int>> permutations;
int n, k, x;

void funcao(vector<int>& cur){
    if (cur.size() == k){
        permutations.push_back(cur);
        return;
    }
    for (int i = 0; i < n; i++){
        cur.push_back(i);
        funcao(cur);
        cur.pop_back();
    }
}

signed main(){
    winton;
    cin >> n >> k >> x;
    vector<int> cur;
    funcao(cur);
    vector<string> ss(n), ans;
    for (auto &s : ss) cin >> s;
    for (auto &vec : permutations){
        string p = "";   
        for (auto i : vec){
            p += ss[i];
        }
        ans.push_back(p);
    }
    sort(all(ans));
    cout << ans[x-1] << endl;
    //for (auto y : ans) cout << y << endl;
}
