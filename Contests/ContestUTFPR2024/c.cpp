#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    int n; cin >> n;
    ll arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    int l = 0, r = 0;
    unordered_map<ll, int> mp;
    int tam = 0, idxi = 0;
    while(l < n && r < n){
        mp[arr[r]]++;
        while(mp[arr[r]] > 1){
            mp[arr[l]]--;
            l++; 
        }
        if(tam < r - l + 1){
            tam = r - l + 1;
            idxi = l;
        }
        r++;
    }

    l = 0; 
    //cout << tam << endl;
    while(l < n){
        if(l == idxi){
            int r = idxi+tam-1;
            while(r >= l){
                cout << arr[r] << " ";
                r--;
            }
            l = idxi+tam-1;
        }else cout << arr[l] << " ";
        l++;
    }
    cout << endl;
}