#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAXN = 1e6+7;

signed main(){
    winton;
    int n;
    cin >> n;
    vector<int> arr(n), cnt(MAXN,0);
    for (auto &i : arr) cin >> i;
    int ans = 0;
    for (int i = 0; i < n; i++){
        if (cnt[arr[i]] > 0)cnt[arr[i]]--;
        else ans++;
        if (arr[i] > 0) cnt[arr[i]-1]++;
    }
    cout << ans << endl;
}
