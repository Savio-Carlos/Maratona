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
    int a, b;
    cin >> a >> b;
    int ans = 0;
    for (int i = 1; i <= a; i++){
        if (a%i == 0){
            if (b >= a-i){
                ans = i;
                break;
            }
        }
    }
     cout << ans << endl;
     
}