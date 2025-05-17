#include <bits/stdc++.h>
using namespace std;
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long
#define ld long double
const int MAXS = 1e5 + 7;

signed main() {
    winton
    int n;
    cin >> n;
    vector<int> arr(n);
    map<int,int> last;
    int ans = INT_MAX;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        if (last.find(arr[i]) != last.end()){
            //cout << "achou repetido " << last[arr[i]] << endl;
            ans = min(ans, i - last[arr[i]] + 1);
        }
        last[arr[i]] = i;
        //cout << last[arr[i]] << endl;
    }
    if (ans == INT_MAX) cout << "-1" << endl;
    else cout << ans << endl;
}