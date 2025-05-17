#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAXN = 55;
const int MOD = 1e9+7;
char grid[MAXN][MAXN];

signed main(){
    winton;
    int n, k;
    cin >> n >> k;
    int rem = n-k;
    priority_queue<int> pq;
    for (int i = 0; i < k; i++){
        int a;
        cin >> a;
        pq.push(-a);
    }
    int ans = 0;
    int tempo = 0;
    while(!pq.empty()){
        int b = -pq.top();
        ans += tempo+b;
        tempo+=b;
        pq.pop();
        if (rem) {
            int a;
            cin >> a;
            pq.push(-a);
            rem--;
        }
        //cout << ans << endl;
    }
    cout << ans << endl;
}