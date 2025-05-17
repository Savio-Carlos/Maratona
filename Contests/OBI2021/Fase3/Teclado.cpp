#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAXN = 1e6+7;
const int LOG = 20;
const int INF = INT_MAX;

signed main () {
    winton;
    string s;
    cin >> s;
    int teclado[] = {'2','2','2','3','3','3','4','4','4','5','5','5','6','6','6','7','7','7','7','8','8','8','9','9','9','9'};
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++){
        string w;
        cin >> w;
        bool possible = true;
        if (s.size() != w.size()) possible = false;
        else {  
            for (int j = 0; j < w.length(); j++){
                if(teclado[w[j]-'a'] != s[j]) possible = false;
            }
        }
        if (possible)ans++;
    }
    cout << ans << endl;
    
}