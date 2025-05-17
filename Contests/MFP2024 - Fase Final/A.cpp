#include <bits/stdc++.h>
using namespace std;
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long
#define ld long double
const int MAXS = 1e5;

signed main() {
    winton
    int n; cin >> n;
    string s = "a";
    for (int i = 1; i < n; i++){
        string temp;
        temp += s;
        temp += 'a' + i;
        temp += s;
        s = temp;
    }
    if (s.size() > MAXS){
        for (int i = 0; i < MAXS; i++){
            cout << s[i];
        }
        cout << endl;
    }
    else cout << s << endl;
}