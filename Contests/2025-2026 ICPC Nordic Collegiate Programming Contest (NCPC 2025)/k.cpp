#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define endl '\n'

#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

signed main(){
    fastio;
    int n; cin >> n;
    int mx = 0;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        if(s == "/") cout << mx << endl;
        else{
            int x = stoi(s);
            if(!(x%10) && x > mx) mx = x + 10;
            else if((x%10) && x > mx){
                for(int i = 0; i < 10; i++){
                    x++;
                    if(!(x%10)) break;
                }
                mx = x;
                
            }
            cout << s << endl;
        }
    }
}