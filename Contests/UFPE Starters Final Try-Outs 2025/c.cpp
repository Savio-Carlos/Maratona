#include <bits/stdc++.h>
using namespace std;


#define int long long
#define ld long double
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)

const int MOD = 1e9+7;
const int MAXN = 1e5+7;
int arr[MAXN];
int n;



signed main(){
    fastio;
    cin >> n;
    int ans = 1, f = -1, lst = -1, val = 0, cnt = 0, cur = 1;
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    for(int i = 0; i < n; i++){
        if(arr[i] == 0){
            f = -1;
            lst = -1;
            val = 0;
            cnt = 0;
            cur = 1;
            continue;
        }
        if(arr[i] < 0){
            cnt++;
            if(f == -1) f = i;
            lst = i;
        }

        if(!(cnt&1)){
            cur = max(cur, arr[i]*cur);
            ans = max(ans, cur);
        }else{
            int cur2 = arr[i]*cur/arr[f];
            int cur3 = arr[i]*cur/arr[lst];
            cur = max({cur, cur2, cur3});
            ans = max(ans, cur);
        }

    }
    cout << ans << endl;

}