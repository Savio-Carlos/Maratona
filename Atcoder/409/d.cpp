#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define debug(x) cout << #x << " = " << x << "\n";
const int MAX = 3e5+7;
const int INF = INT_MAX;

int mp[MAX];

signed main(){
    //winton;
    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n >> s;
        if (n == 1) {
            cout << s << endl;
            return 0;
        }
        int sub = 0;
        char csub;
        for (int i = 0; i < n-1; i++){
            if (s[i+1] < s[i]){
                sub = i;
                csub = s[i];
                break;
            } 
        }
        s.erase(s.begin() + sub);
       // cout << s << endl;
        int pos = max(sub-1,0LL);
        while(pos < n-1 && csub <= s[pos]){
            pos++;
        }
        if (pos == n) s.push_back(s[pos]);
        else s.insert(s.begin() + pos+1, csub);
        cout << s << endl;
    }
}