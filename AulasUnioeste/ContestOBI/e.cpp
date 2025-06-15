#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAX = 505;
const int INF = INT_MAX;

signed main(){
    winton;
    int n;
    cin >> n;
    int x,y,ans = 0;
    int tot = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            int a;
            cin >> a;
            ans += a;
            if (!a){
                x=i;
                y=j;
            }
        }
    }
    for (int i = 1; i<= n*n; i++){
        tot += i;
    }
    cout << tot - ans << endl << x << endl << y << endl;
}