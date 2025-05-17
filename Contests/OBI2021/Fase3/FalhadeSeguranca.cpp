#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAXN = 1e6+7;
const int LOG = 20;
const int INF = INT_MAX;

signed main () {
    winton;
    int n;
    cin >> n;
    int ans = 0;
    map<string, int> mp;
    vector<string> palavras;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        palavras.push_back(s);
    }

    for(int i = 0; i < n; i++){
        string s = palavras[i];
        set<string> temp;
        for (int j = 0; j < s.size(); j++){
            string sub;
			for(int k=j; k<s.size(); k++){
				sub.push_back(s[k]); 
				temp.insert(sub);
			}
            
        }
        for (auto u : temp){mp[u]++;}
    }

    for (auto u : palavras){
            ans+=mp[u];
            //cout << "+" << mp[u] << " " << u << endl;;
    }

    cout << ans - n << endl;
}