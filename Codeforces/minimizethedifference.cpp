#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main (){
    int t, n;
    cin >> t;
    while (t--){
        cin >> n;
        
        vector<ll> arr (n);
        for (int i = 0; i < n; i++){
            cin >> arr[i];
        }
        ll len = 0, sum = 0, mx = 0, mn = 1e18;

        for (int i = n-1; i >= 0; i--){
            sum += arr[i];
            len++;
            mx = max(mx, (sum+len-1)/len);
        }
        sum = 0;
        len = 0;
        for (int i = 0; i < n; i++){
            sum += arr[i];
            len++;
            mn = min(mn, sum/len);
        }
        cout << mx - mn << endl ;
        
    }
}


/*
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
#def

int main(){

#endif

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector<LL> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        ll
        {
            int len = 0; LL sum = 0;
            for(int i = n - 1; i >= 0; i--){
                sum += a[i];
                len += 1;
                mx = max(mx, (sum + len - 1) / len);
            }
        }
        {
            int len = 0; LL sum = 0;
            for(int i = 0; i < n; i++){
                sum += a[i];
                len += 1;
                mn = min(mn, sum / len);
            }
        }
        cout << mx - mn << '\n';
    }

}
 */