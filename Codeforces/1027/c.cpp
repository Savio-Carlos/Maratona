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
        vector<int> arr(n);
        vector<int>seq;
        int cur = 1;
        for (int i = 0; i < n; i++){
            cin >> arr[i];
            if (i > 0){
                if (arr[i] == arr[i-1]+1) cur++;
                else if(arr[i] < arr[i-1]+1) continue;
                else {
                    seq.push_back(cur);
                    cur = 1;
                }
            }
        }
        seq.push_back(cur);
        int ans = 0;
        for (auto u : seq) {
            //cout << u << " ";
            if (u > 1) ans += (u+1)/2;
            else ans++; 
        }
        cout << ans << endl;
    }
}