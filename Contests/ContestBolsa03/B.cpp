#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)

signed main () {
    winton;
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> ans(n-1);
    
    for (int i = 1; i < n; i++){
        int l = n - i;
        int a;
        for (int k = 1; k <= l; k++){
            if (s[k-1] == s[k+i-1]){
                a = k-1;
                break;
            }
            else a = l;
        }
        ans[i-1] = a;
    }
    for (auto u : ans) cout << u << endl;
}