#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAXN = 1e6+7;

signed main(){
    winton;
    int n, x, y;
    cin >> n >> x >> y;
    int mid = 1<<(n-1), corner = (1<<n), ans = 0;

    while(x!=mid || y!=mid){
        int i = (x>=mid) ? 1 : 0;
        int j = (y>=mid) ? 1 : 0;

        x = 2*x - i*corner;
        y = 2*y - j*corner;
        ans++;
        //cout << x << " , " <<y << endl;
        //depressao
    }
    cout << ans << endl;
}