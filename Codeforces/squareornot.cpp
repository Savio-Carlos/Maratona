#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll t, n;
    cin >> t;
    string s;
    while (t--){
        cin >> n;
        cin >> s;
        int cnt = 0;
        for (int i = 0; i < s.length(); i++){
            if (s[i] == '0') cnt++;
            //cout << i << endl;
        }
        //cout << cnt;
        int r = sqrt(n);
        cout << r << endl;
        if (cnt == (r-2)*(r-2)){
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }


}