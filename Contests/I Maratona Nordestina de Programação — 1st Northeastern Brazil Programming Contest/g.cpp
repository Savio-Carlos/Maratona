#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(0),cin.tie(0)

signed main(){
    fastio;
    int q;
    cin >> q;
    int ans = 0;
    deque<char> dq;
    int A = 0, B = 0;
    while(q--){
        int t;
        char c;
        cin >> t;
        if (t == 1){
            cin >> c;
            if (c == 'A') A++;
            else {
                B++;
                ans += A;
            }
            dq.emplace_back(c);
        }
        else if (t == 2){
            cin >> c;
            if (c == 'B') B++;
            else {
                A++;
                ans += B;
            }
            dq.emplace_front(c);
        }
        else if (t == 3){
            c = dq.back();
            dq.pop_back();
            if (c == 'B'){
                ans -= A;
                B--;
            }
            else {
                A--;
            }
        }
        else if (t == 4){
            c = dq.front();
            dq.pop_front();
            if (c == 'A'){
                ans -= B;
                A--;
            }
            else {
                B--;
            }
        }
        cout << ans << endl;
    }
}