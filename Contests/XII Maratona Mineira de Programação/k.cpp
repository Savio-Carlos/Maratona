#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fastio ios_base::sync_with_stdio(false),cout.tie(0),cin.tie(0)

/*
obrigatorio q todos os ti da resposta sejam distintos
*/

signed main(){
    fastio;
    int n; cin >> n;
    set<pair<int, int>> ans;
    int cnt = 0; 
    for(int i = 0; i < n; i++){
        int p, x; cin >> p >> x;
        if(x == 0){
            ans.insert({p, 0});
        }else{
            cnt++;
            int v = p + x;
            ans.insert({(p+x)*cnt, cnt});
        }
    }

    cout << ans.size() << endl;
    for(auto [a, b] : ans){
        cout << a << " " << b << endl;
    }
}