#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define int long long
#define ld long double
#define winton ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

signed main(){
    winton;
    map<string, set<int>> quem;
    map<string,int> freq;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int w;
        cin >> w;
        for (int j = 0; j < w; j++){
            string s;
            cin >> s;
            freq[s]++;
            quem[s].insert(i);
        }
    }
    vector<pair<int,string>> ans;
    for (auto [s,st] : quem){
        if (st.size() == n) ans.push_back({freq[s], s});
    }
    sort(rall(ans));
    for (auto [_,s] : ans) cout << s << endl;
}