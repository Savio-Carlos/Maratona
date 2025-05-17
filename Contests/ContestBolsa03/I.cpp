#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)

signed main () {
    winton;
    int n;
    cin >> n;
    string s;
    cin >> s;
    s+="A";
    int cur = 0;
    int ans = 0;
    pair<int,int> lastA = {0,-1}, lastB = {0,-1};
    for (int i = 0; i < n; i++){
        if (s[i] == s[i+1]) cur++;
        else{
                   if (s[i] == 'a'){
            if (lastA.first + cur >= lastB.first){
                ans = max(ans, lastB.first * 2);
            }
            else if (cur <= lastB.first){
                ans = max(ans, cur * 2);
            }
        }
        else if (s[i] == 'b'){
            if (lastB.first + cur >= lastA.first){
                ans = max(ans, lastA.first * 2);
                //cout << "debug " << endl;
            }
            else if (cur <= lastA.first){
                ans = max(ans, cur * 2);
            }
        }
            if (s[i] == 'b'){
                lastB.second = i;
                lastB.first =  i - lastA.second;
                cur = 1;
            }
            else if (s[i] == 'a'){
                lastA.second = i;
                lastA.first =  i - lastB.second ;
                cur = 1;
               // cout << lastA.second << " " << lastA.first << endl;
            }
        }
 
        //cout << lastA.first << " " << lastB.first << " i:" << i << endl; 
        //cout << ans << endl;
        //cout << "cur " <<  cur << endl;
    }
    cout << ans << endl;

}