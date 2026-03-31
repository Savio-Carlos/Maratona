#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int long long
#define ld long double
#define endl '\n'

#define winton ios_base::sync_with_stdio(false),cin.tie(0)

signed main(){
    winton;

    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    int cnt = 0, shop = 0;
    for (int i = 0; i < s.size(); i++){
        cnt++;
        if (cnt == n){
            cnt = 0;
            ans += shop;
            shop++;
        }
        if (s[i] == '1') ans+=2;
    }
    cout << ans << endl;
}