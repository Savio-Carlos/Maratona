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

signed main(){
    winton; 
    int n, k, p;
    cin >> n >> k >> p;
    priority_queue<pair<int,int>> pq;
    vector<int> a;
    map<int,int> cnt;

    int q;
    cin >> q;
    for (int i = 0; i < q; i++){
        int x;
        cin >> x;
        cnt[x]++;
        a.push_back(x);
    }  
    for (int i = 1; i <= k; i++){
        if (cnt.find(i) == cnt.end()){
            cnt[i] = 0;
        }
        //debug(i);
        //debug(cnt[i]);
        pq.push({-cnt[i],i});
    }
    for (int i = q; i < n; i++){
        auto [qtd, cor] = pq.top();
        pq.pop();
        a.push_back(cor);
        pq.push({qtd-1, cor});
    }
    map<int,int> last;
   // vdebug(a);
    for (int i = 0; i < n; i++){
        if (last.find(a[i]) != last.end()){
            if (i - last[a[i]] < p){
                //debug(a[i]);
                cout << "impossible" << endl;
                return 0;
            }
        }
        last[a[i]] = i;
    }

    for (auto u : a) cout << u << " ";
    cout << endl;
}
