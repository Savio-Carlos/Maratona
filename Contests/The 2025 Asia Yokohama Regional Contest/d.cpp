#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()


void dbg_out() {cerr << endl;}
template<typename H, typename... T>
void dbg_out(H h, T... t) {cerr << ' ' << h; dbg_out(t...);}

#define DEBUG

#if defined(DEBUG)
    #define fastio (void)0
    #define debug(...) cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__);
#else 
    #define fastio ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL)
    #define debug(...) (void)0
#endif


signed main(){
    fastio;
    string s; cin >> s;
    int n = s.size();
    int pos = 0;
    if(s[0] == '1' && s[1] == '0'){
        string t = "9";
        int i = 2;
        for(; i < n; i++){
            t += s[i];
        }
        int v = stoll(s) - stoll(t);
        cout << t << v << endl;
        return 0;
    }else if (s[0] == '1' && s[1] != '0'){
        pos = 1;
        string t = "";
        for(int i = 1; i < n; i++){
            t += s[i];
        };
        s = t;
        n--;
        //cout << s << endl;
    }
    int k = s[0] - '0';
    k--;
    string t = to_string(k);
    for(int i = 1; i < n; i++){
        t += s[i];
    }
    //cout << t << endl;
    int v = stoll(s) - stoll(t);
    if(pos) cout << 1;
    cout << t << v << endl;
}