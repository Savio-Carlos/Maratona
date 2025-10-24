#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

signed main(){
    fastio;
    int n, h;
    cin >> n >> h;
    int ans = 0;
    bool pos = true;
    for (int i = 0; i < n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        vector<int> cur(3);
        cur[0] = a;
        cur[1] = b;
        cur[2] = c;
        sort(all(cur));
        int j = -1;
        while ((j + 1) < 3 && cur[j+1] <= h) j++;
        if (j == -1) pos = false;

        if(cur[1] <= h)ans+=cur[0];
        else ans += cur[1];
        
    }
    if(pos) cout << ans << endl;
    else cout << "impossible" << endl;
}