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

signed main(){
    winton; 
    int n;
    cin >> n;
    vector<string> ans;
    for(int j = 0; j < n; j++){
        string s;
        cin >> s;
        string type = "\U0001F4AA";
        for (int i = 0; i < s.size(); i++){
            if (s[i] == 'r'){
                if (i < s.size()-3 && s[i+1] == 'e' && s[i+2] == 's' && s[i+3] == 't') type = "\U0001F634";
            }
            if (type == "\U0001F634") break;
            if (s[i] == 'l'){
                if (i < s.size()-2 && s[i+1] == 'e' && s[i+2] == 'g') type = "\U0001F9B5";
            }

        }
        ans.push_back(type);
    }
    //vdebug(ans);
    int cnt = 0, semana = 1;
    for (int i = 0; i < 31; i++){
        if (cnt == 0){
            cout << semana << " ";
            semana++;
        }
        cout << ans[i%ans.size()];
        cnt++;
        if (cnt == 7) {
            cout << endl;
            cnt = 0;
        }
    }
    cout << endl;
}


    //cout << "Emoji sorrindo: \U0001F600" << endl;

