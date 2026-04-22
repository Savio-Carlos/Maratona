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
const int MOD = 998244353;
const int INF = 0x3f3f3f3f3f3f3f3fLL;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<pair<int,int>> numbers;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        numbers.push_back({x,i});
    }
    sort(all(numbers));
    tuple<int,int,int> ans = {-1,-1,-1};
    int best = -1;
    for (int i = 1; i < n; i++){
        auto &[a, idxa] = numbers[i];
        auto &[b, idxb] = numbers[i-1];

        int x = a ^ ((1<<k) - 1);
         
        int e = (a^x)&(b^x);
        if (e > best){
            best = e;
            ans = {x, idxa, idxb};
        }
    }
    auto &[u,v,w] = ans;
    if (v > w) swap(v,w);
    cout << v << " " << w << " " << u << " " << endl;
}
    
signed main(){
    winton;
    int t;
    cin >> t;
    while(t--)solve();
}
