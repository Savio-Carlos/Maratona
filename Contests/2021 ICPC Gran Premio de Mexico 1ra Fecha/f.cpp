#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define ld long double
#define winton ios_base::sync_with_stdio(0),cin.tie(0)
#define all(x) x.begin(),x.end()
#define debug(x) cerr << #x << ": " << x << endl;

signed main(){
    winton;
    int n;
    ld d;
    cin >> n >> d;

    int diff = llround(d*1000);

    auto f = [&](int x) -> string {
        int mil = x % 1000; 
        x /= 1000;
        int s = x % 60;     
        x /= 60;
        int m = x % 60;     
        x /= 60;
        int h  = x;

        // debug(h);
        // debug(m);
        // debug(s);
        // debug(mil);
        return (h < 10 ? "0" : "") + to_string(h) + ":" + (m < 10 ? "0" : "") + to_string(m) + ":" + (s < 10 ? "0" : "") + to_string(s) + "," + 
        (mil < 100 ? "0" : "") + (mil < 10 ? "0" : "") + to_string(mil);
    };

    string line;
    getline(cin, line);

    while(getline(cin,line)){
        int h1,m1,s1,x1,h2,m2,s2,x2;
        if (sscanf(line.c_str(), "%lld:%lld:%lld,%lld --> %lld:%lld:%lld,%lld",&h1,&m1,&s1,&x1,&h2,&m2,&s2,&x2) == 8){
            int a = ((h1*60+m1)*60+s1)*1000 + x1 + diff;
            int b = ((h2*60+m2)*60+s2)*1000 + x2 + diff;
            // debug(a);
            // debug(b);
            cout << f(a) << " --> " << f(b) << endl;
        }
        else{
            cout << line << endl;
        }
    }

}


