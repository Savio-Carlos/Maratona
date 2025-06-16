#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define debug(x) cout << #x << " = " << x << "\n";
const int MAX = 2e5+7;
const int INF = INT_MAX;

signed main(){
    winton;
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> remove;
    int aux = k;
    for (int i = 0; i < n; i++){
        if (s[i] == '.' && aux){
            remove.push_back(i);
            aux--;
        }
    }
    string t = "";
    int len = remove.size();
    for (int i = 0; i < min(k,len); i++){
        t += ".";
    }
    for (int i = len-1; i >= 0; i--){
        s.erase(s.begin()+remove[i]);
    }
    //cout << s << endl;
    t+=s;
    cout << t << endl;
}