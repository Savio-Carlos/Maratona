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

*/

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> p(n+1);
        for (int i = 1; i <= n; i++){
            cin >> p[i];    
        }
        
        for (int i = 1; i <= n; i++){
            int cur = i;
            while(p[cur] != i){
                cout << cur << " ";
                cur = p[cur];
            }
            cout << cur << endl;
        }
    }
}