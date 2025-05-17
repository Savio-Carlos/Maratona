#include <bits/stdc++.h>
using namespace std;
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long
#define ld long double
const int MAXS = 1e5;

signed main() {
    winton
    int n, m;
    cin >> n;
    vector<vector<string>> frases(n+1);
    for (int i = 0; i <= n; i++){
        string s, t; 
        getline(cin, s);
        stringstream X(s);
        while (getline(X, t, ' ')) {
            frases[i].push_back(t);
            //cout << t << endl;
        }
        //cout << endl;
    }
    cin >> m;
    map<string,int> scores;
    for (int i = 0; i < m; i++){
        int v;
        string s;
        cin >> s >> v;
        scores[s] = v;
    }
    int ans1 = 0;
    pair<int,int> ans2;
    for (int i = 0; i < frases.size(); i++){
        int cur = 0;
        for (auto s : frases[i]){
            cur += scores[s];
        }
        ans1 += cur;
        if (cur >= ans2.second){
            ans2.second = cur;
            ans2.first = i;
        }
    } 
    cout << ans1 << " " << ans2.first << endl;
}