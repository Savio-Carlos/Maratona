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
    int n, m;
    cin >> n >> m;
    vector<int> arr(n+1);
    vector<pair<int,int>> walls(m); 
    for (auto &[a,b] : walls){
        cin >> a >> b;
        arr[a-1]++;
        arr[b]--;
    }
    for (int i = 1; i < n; i++){
        arr[i] += arr[i-1];
    }
    int ans = INT_MAX;
    for (int i = 0; i < n; i++){
        ans = min(arr[i],ans);
        //cout << arr[i] << " ";
    }
    cout << ans << endl;
}