#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAX = 2e5+7;
const int INF = INT_MAX;

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        pair<int,int> ans = {-1,-1};
        for (int i = 0; i <= 100; i++){
            for (int j = 0; j <= 100; j++){
                if ((i+j)*(i+j) == n) {
                    ans.first = i;
                    ans.second = j;
                    break;
                }
            }
        }
        if (ans.first == -1) cout << -1 << endl;
        else cout << ans.first << " " << ans.second << endl;
    }
}