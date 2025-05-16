#include <bits/stdc++.h>
using namespace std;
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long
#define ld long double
const int MAXN = 1e9+7;

signed main() {
    winton;
    int n, q;
    string s;
    cin >> n;
    cin >> s;
    int mais = 0, menos = 0;
    for (int i = 0; i < n; i++){
        if (s[i] == '+') mais++;
        else menos++;
    }
    cin >> q;
    int total = mais - menos;
    while (q--){
        int a, b;
        cin >> a >> b;
        if(b == a) {
            if(total == 0)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
            continue;
        }
        int k = (total * b) / (b - a);
        if ((total * b) % (b - a) != 0) cout << "NO" << endl;
        else if (k >= -menos && k <= mais) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}