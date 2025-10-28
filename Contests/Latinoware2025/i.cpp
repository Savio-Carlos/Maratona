#include <bits/stdc++.h>
#define int long long
#define ld long double
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

signed main(){
    fastio;
    string s, t;
    cin >> s >> t;
    bool ver = false, hor = false;
    for (auto u : t){
        if (u == 'v') ver = !ver;
        else if (u == 'h') hor = !hor;
        else {
            hor = !hor;
            ver = !ver;
        }
    }
    if (ver && hor){
        reverse(all(s));
        for (auto &c : s){
            if(c == 'b') c = 'q';
            else if (c == 'q') c = 'b'; 
            else if (c == 'd') c = 'p'; 
            else if (c == 'p') c = 'd'; 
        }
    }
    else if (ver && !hor){
        for (auto &c : s){
            if(c == 'b') c = 'p';
            else if (c == 'p') c = 'b'; 
            else if (c == 'q') c = 'd'; 
            else if (c == 'd') c = 'q'; 
        }
    }
    else if (hor && !ver){
        reverse(all(s));
        for (auto &c : s){
            if(c == 'b') c = 'd';
            else if (c == 'd') c = 'b'; 
            else if (c == 'q') c = 'p'; 
            else if (c == 'p') c = 'q'; 
        }
    }
    cout << s << endl;
    
}