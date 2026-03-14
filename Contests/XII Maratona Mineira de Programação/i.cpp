#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
// #define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fastio ios_base::sync_with_stdio(false),cout.tie(0),cin.tie(0)

signed main(){
    fastio;
    int n;
    cin >> n;
    cout << "L 1" << endl;
    int prev, ci;
    cin >> prev;
    int ref = -1;

    for (int j = 1; j <= n; j++){
        cout << "C " << j << endl;
        cin >> ci;
        cout << "L 1" << endl;
        int curr;
        cin >> curr;
        int lamp_state = (curr > n - prev) ? 1 : 0;

        if (j == 1){
            ref = lamp_state;
            prev = curr;
        } 
        else {
            int effective_ref = ref ^ ((j - 1) % 2);
            if (lamp_state != effective_ref){
                cout << "C " << j << endl;
                cin >> ci;
                prev = curr - (2 * lamp_state - 1);
            } 
            else {
                prev = curr;
            }
        }
    }

    for (int i = 1; i <= n; i++){
        cout << "L " << i << endl;
        int li;
        cin >> li;
        if (li == 0){
            cout << "L " << i << endl;
            cin >> li;
        }
    }
    cout << "FIM" << endl;
}