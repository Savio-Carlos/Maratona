#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long

signed main(){
    fastio;
    int n, k; cin >> n >> k;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    int l = 0, r = 0;
    int ans = 0;
    int sum = arr[0], equal = 0, qtd = 0;
    map<int, int> mp;
    while(l < n && r < n){
        while(sum <= k && r < n){
            qtd++;
            //somo primeiro e dps checo
            mp[arr[r]]++;
            if(mp[arr[r]] >= 2 && !((mp[arr[r]])&1)){
               // cout << mp[arr[r]] << " " << arr[r] << endl;
                equal += 2;
            }
            //calculando a quantidade de quartas iguais
            ans = max(ans, equal);
            r++;
            sum += arr[r];
        }
        while(sum > k && l < n){
            sum -= arr[l];
            l++;
            qtd--;
            if(!(mp[arr[l]])&1) equal--;
            mp[arr[l]]--;
        }
    }
    cout << ans/2 << endl;
}