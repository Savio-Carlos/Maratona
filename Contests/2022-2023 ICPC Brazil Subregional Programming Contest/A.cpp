#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAXN = 1e5+7;

signed main(){
    winton;
    int n;
    cin >> n;
    string s;
    cin >> s;
    s += '5';
    int cnt = 0;
    for (int i = 0; i < n; i++){
        if (s[i] == 'a' && s[i+1] == 'a'){
            cnt++;
            while (s[i+1] == 'a' && i < n){
                i++;
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}