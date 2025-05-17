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
    vector<int> v;
    while(l < n){
        if(l == idxi){
            int r = idxi+tam-1;
            while(r >= l){
                v.push_back(arr[r]);
                r--;
            }
            l = idxi+tam-1;
        }else{
            v.push_back(arr[l]);
        }
        l++;
    }
    //cout << endl;

    for(int i = 0; i < n; i++){
        if(i == n -1) cout << v[i] << endl;
        else cout << v[i] << " ";
    }
}