#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

signed main(){
    fastio;
    string s, t;
    cin >> s >> t;
    bool hor = 0, ver = 0;
    for (auto c : t){
        if (c == 'h') hor = !hor;
        else if (c == 'v') ver = !ver;
        else{
            hor = !hor;
            ver = !ver;
        } 
    }
    if (hor && !ver){
        //cout << "1 if\n";
        reverse(all(s));
        for (auto &c : s){
            if (c == 'p') c = 'q';
            else if (c == 'q') c = 'p';
            else if (c == 'd') c = 'b';
            else if (c == 'b') c = 'd';
        }
    }
    else if (hor && ver){
               // cout << "2 if\n";
        reverse(all(s));
        for (auto &c : s){
            if (c == 'b') c = 'q';
            else if (c == 'q') c = 'b';
            else if (c == 'p') c = 'd';
            else if (c == 'd') c = 'p';
        }
    }
    else if (!hor && ver){
                //cout << "3 if\n";
        for (auto &c : s){
            if (c == 'p') c = 'b';
            else if (c == 'b') c = 'p';
            else if (c == 'q') c = 'd';
            else if (c == 'd') c = 'q';
        }
    }
    //cout << hor << " " << ver << endl; 
    cout << s << endl;
}