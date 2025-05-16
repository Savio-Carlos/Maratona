#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

int main(){
    fastio;
    int t;
    cin >> t;
    while (t--){
        int n, ans = 0; cin >> n;
        string s;
        cin>> s;
        for(int i = 0; i < n; i++){
            if (s[i] == 'm' && s[i+1] == 'a' && s[i+2] == 'p') {
                ans++;
                i+=2;
            }
            else if (s[i] == 'p' && s[i+1] == 'i' && s[i+2] == 'e') {
                ans++;
                i+=2;
            }
        }
        cout << ans << endl;
    }
}
