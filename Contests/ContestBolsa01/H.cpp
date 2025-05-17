#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long
#define vi vector<int>
#define pb push_back
const int MAXL = 1e9+7;

signed main(){_
    int n; cin >> n;
    string s; cin >> s;
    int ans = 0;
    int  cur = 1;
    pair<int,int> lastA = {-1,0}, lastB = {-1,0};
    for (int i = 1; i < n; i++){
        if (s[i] == s[i-1]) cur++;
        else {
            if (s[i-1] == 'a'){
                lastA = {i - cur, cur};
            }
            else {
                lastB = {i - cur, cur};
            }
            cur = 1;
        }
        if (s[i] == 'a'){
            if (cur + lastA.second >= lastB.second) ans = max(ans, lastB.second*2);
            else if (lastB.second >= cur) ans = max(ans, cur*2);
        }
        else if (s[i] == 'b'){
            if (cur + lastB.second >= lastA.second) ans = max(ans, lastA.second*2);
            else if (lastA.second >= cur) ans = max(ans, cur*2);
        }
        //cout << "ans = " << ans << " i = " << i << endl;
    }
    cout << ans << endl;
    
    
}
