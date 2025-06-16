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
            continue;
        }
        int sub = -1;
        char csub;
        for (int i = 0; i < n-1; i++){
            if (s[i] > s[i+1]){
                sub = i;
                csub = s[i];
                break;
            } 
        }
        if (sub == -1){
            cout << s << endl;
            continue;
        }
        s.erase(s.begin() + sub);

        int pos = -1;
        for (int i = 0; i < n-1; i++){
            if (s[i] > csub){
                pos = i;
                break;
            }
        }
        if (pos != -1) s.insert(s.begin() + pos, csub);
        else s.push_back(csub);
        cout << s << endl;
    }
}