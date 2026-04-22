#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long
const int MAXL = 1e5+7;

signed main() {_
    int t; cin >> t;
    while(t--){
        int n, x, y;
        cin >> n >> x >> y;
        vector<int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        map<pair<int,int>,int> mp;
        int ans = 0;
        for (int i = 0; i < n; i++){
            int xtarget = x - (a[i] % x); //procurar o numero que somado a a[i] resulta em um numero divisivel por x
            if (xtarget == x) xtarget = 0; //se o numero for x, ele ja e divisivel por x
            ans += mp[{xtarget, a[i]%y}];  
            mp[{a[i]%x, a[i]%y}]++; //incrementa o numero de pares que somados resultam em um numero divisivel por x e y
            //cout << "mp[{a[i]%x, a[i]%y}] " << mp[{a[i]%x, a[i]%y}] << endl; 
            //cout << "a[i]%x " << a[i]%x << endl; 
            //cout << "a[i]%y " << a[i]%y << endl; 
        }
        cout << ans << endl;
    }

}