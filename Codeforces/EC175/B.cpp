#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long
const int MAXL = 1e9+7;

signed main(){_
    int t; cin >> t;
    while (t--){
        int n, x, k;
        string s;
        cin >> n >> x >> k;
        cin >> s;
        vector<int> a(n+1, x);
        for (int i = 0; i < n; i++){
            a[i+1] = a[i];
            if (s[i] == 'R') a[i+1]++;
            else a[i+1]--;
        }

        if(count(a.begin()+1,a.end(),0) == 0){
            cout << "0" << endl;
            continue;
        }    
    
        int first = 0;
        while(a[first] != 0)first++;
        if (first > k){
            cout << "0" << endl;
            continue;
        }

        k-=first;
        int ans = 1;
        int p = 1;
        while (p <= n && a[p] != x)p++; 
        if (p > n) cout << "1" << endl;
        else cout << ans + (k/p) << endl;
    }
}