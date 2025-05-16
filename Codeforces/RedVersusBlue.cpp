#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long
#define ld long double
const int MAXL = 1e5+7;

signed main() {_
    int t; cin >> t;
    while (t--){
        int n, r, b;
        cin >> n >> r >> b;
        int seg = b+1;
        int redmin = r/seg;
        int redextra = r%seg;

        string s;
        for (int i = 0; i < seg; i++){
            int add = redmin + (i < redextra ? 1 : 0);
            for (int j = 0; j < add; j++) {
                s += 'R';
            }
            if (i < b) {
                s += 'B';
            }
        }
        
        cout << s << endl;
    }
}