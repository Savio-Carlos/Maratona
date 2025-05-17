#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MOD = 1e8;
const int MAXN = 1e2+7;
const int MAXM = 1e4+7;

signed main(){  
    winton;
    int t, n, mini = INT_MAX;
    cin >> n >> t;
    vector<int> tempos(n);

    for (int i = 0; i < n; i++){
        cin >> tempos[i];
        mini = min(mini, tempos[i]);
    }

    int l = 0;
    int r = t*mini;
    int ans = 0;

    while(l<=r){
        int mid = l + (r-l)/2;
        int sum = 0;
        for (int i = 0; i < n; i++){
            sum+=(mid/tempos[i]);
            if (sum >= t) break;
        }

        if (sum>=t){
            ans = mid;
            r = mid-1;
        }
        else {
            l = mid+1;
        }
    }

    cout << ans << endl;

}