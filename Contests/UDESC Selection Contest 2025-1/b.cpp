#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define debug(x) cout << #x << " = " << x << "\n";
const int MAX = 2e5+7;
const int INF = INT_MAX;

signed main(){
    winton;
    int n;
    string s;
    cin >> n >> s;
    string t = s;
    sort(all(t));
    if (s == t){
        cout << s << endl;
        return 0;
    }
    int idx = -1;
    for (int i = 0; i < n; i++){
        if (s[i] != t[i]){
            idx = i;
            break;
        }
    }

    char sub = t[idx];
    int troca = -1;
    for (int j = n - 1; j >= 0; --j) {
        if (s[j] == sub) {
            troca = j;
            break;
        }
    }
    swap(s[idx], s[troca]);
    cout << s << endl;
}