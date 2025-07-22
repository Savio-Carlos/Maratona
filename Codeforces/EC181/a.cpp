#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
const int MAX = 2e5+7;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f3f3f3f3fLL;

void solve(){
    string s;
    cin >> s;
    sort(all(s));
    vector<int> remove;
    int ff = 0, t = 0, tt = 0, n = 0; 
    for (int i = 0; i < s.size(); i++){
        if (s[i] == 'F'){
            ff++;
            remove.push_back(i);
        }
        if (s[i] == 'T'){
            tt++;
            remove.push_back(i);
        }
        if (s[i] == 'N'){
            n++;
            remove.push_back(i);
        }
    }
    for (int i = remove.size()-1; i >= 0; i--){
        s.erase(s.begin()+remove[i]);
    }
    while(tt--) cout << 'T';
    while(ff--) cout << 'F';
    while(n--) cout << 'N';
    cout << s << endl;
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--)solve();
}