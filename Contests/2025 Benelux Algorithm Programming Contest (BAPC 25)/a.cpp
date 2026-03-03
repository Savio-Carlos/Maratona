#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false),cout.tie(0),cin.tie(0) 

const int MAX = 1e3+7;
ld ev[MAX];

signed main(){
    fastio;
    string s;
    cin >> s;
    int n = s.size();
    ev[0] = 0.0;
    ev[1] = s[0] - '0';
    for (int i = 2; i <= n; i++){
        int num = s[i-1] - '0';
        cout << num << " " << ev[i-1] + num << " " << (ev[i-1]+num) * 0.45 << endl;
        
        ev[i] += ((ev[i-1] + num) * 0.45);
        ev[i] += ((ev[i-1] - num) * 0.45);
        int prev = num;
        for (int j = i-1; j >= 1; j--){

            prev += (s[j] - '0') * 
        }
    }

    for (int i = 1; i <= n; i++){
        cout << i << " ev: " << ev[i] << endl;
    }


}