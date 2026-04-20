#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int long long
#define ld long double
#define endl '\n'

#define fastio ios_base::sync_with_stdio(false),cin.tie(0)

signed main(){
    fastio;
    for (int i = 0; i < 8; i++){
        string s;
        cin >> s;
        int cnt = 0;
        for (char c : s){
            if (c == '.') {
                cnt++;
            } 
            else {
                if (cnt) {
                    cout << cnt;
                    cnt = 0;
                }
                cout << c;
            }
        }
        if (cnt) cout << cnt;
        if (i < 7) cout << '/';
    }
    cout << endl;
}

