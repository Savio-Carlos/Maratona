#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAX = 5e5+7;
const int INF = LLONG_MAX;

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        int best[MAX] = {};
        map<int,int> mp;
        for (int i = 0; i < n; i++){
            cin >> arr[i];
        }
        arr.push_back(-1);
        for (int i = 0; i < n; i++){
            if(arr[i] == arr[i+1]){
                int l = i;
                while(arr[i] == arr[i+1]){
                    i++;
                }
                int r = i;
                if (best[arr[i]] < r-l+1){
                    mp[arr[i]] = r-l+1;
                    best[arr[i]] = r-l+1;
                }
            }  
            else{
                if (best[arr[i]] != 0) continue;
                else {
                    best[arr[i]] = 1;
                    mp[arr[i]] = 1;
                }
            } 
        }
        int ans = INF;
        for (auto u : mp){
            //cout << u.first << ": " << u.second.first << " - " << u.second.second << endl;
            int cost = (n - u.second)*u.first;
            ans = min(ans,cost);
        }
        cout << ans << endl;
    }
}