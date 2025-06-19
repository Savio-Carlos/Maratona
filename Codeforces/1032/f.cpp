#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define debug(x) cout << #x << " = " << x << "\n";
const int MAX = 2e5+7;
const int INF = INT_MAX;

/*
so insiro no vetor de frequencias quando eu chegar num x, pois isso significa que entre 
o momento que eu achei aquela frequencia e o meu atual, eu passe por um x
se eu n tivesse passado entao eu n teria inserido
*/

void solve(){
    int n, s, x;
    cin >> n >> s >> x;
    vector<int> a(n);
    for(int &i : a) cin >> i;
    map<int,int> mp;
    queue<int> q;
    int sum = 0, ans = 0;
    q.push(0);
    for (int i = 0; i < n; i++){
        sum+=a[i];
        if (a[i] > x){
            mp.clear();
            while(!q.empty()) q.pop();
            q.push(sum);
            continue;
        }
        if (a[i] == x){
            while(!q.empty()){
                mp[q.front()]++;
                q.pop();
            }
        }
        q.push(sum);
        ans += mp[sum-s];
    }
    cout << ans << endl;
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--) solve();
}