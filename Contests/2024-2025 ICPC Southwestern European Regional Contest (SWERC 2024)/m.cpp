#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

signed main(){
    fastio;
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'O') cout << ".-.-";
        else cout << ".-";
    }
    cout << endl;
}