#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAX = 11;
const int INF = INT_MAX;

int fib[MAX+1];

void calc(){
    fib[0] = fib[1] = 1;
    for (int i = 2; i < MAX; i++){
        fib[i] = fib[i-1] + fib[i-2];
    }
}

signed main(){
    //winton;
    calc();
    int t;
    cin >> t;
    while(t--){
        vector<int> ans;
        int n, m;
        cin >> n >> m;
        int volume = 0;
        int sidemax = fib[n] + fib[n-1];
        for(int i = 0; i < n; i++){
            volume += (fib[i]*fib[i]*fib[i]);
        }
        for (int i = 0; i < m; i++){
            int h,w,l;
            cin >> w >> l >> h;
            if (h >= sidemax && w*l*h >= volume && l >= fib[n] && w >= fib[n]) ans.push_back(1);
            else if (l >= sidemax && w*l*h >= volume && w >= fib[n] && h >= fib[n]) ans.push_back(1);
            else if (w >= sidemax && w*l*h >= volume && h >= fib[n] && l >= fib[n]) ans.push_back(1);
            else  ans.push_back(0);
        }
        for (auto u : ans) cout << u;
        cout << endl;
    }
}