#include <bits/stdc++.h>
using namespace std;


// #define int long long
#define ld long double
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)

struct trie{
    vector<vector<int>> to;
    vector<int> end, pref;
    int sigma;
    char norm;
    trie(int sigma_= 26, char norm_ ='a') : sigma(sigma_), norm(norm_){
        to = {vector<int>(sigma)};
        end = {0}, pref = {0};
    }

    void insert(string s){
        int x = 0;
        for(auto c : s){
            int &nxt = to[x][c-norm];
            if (!nxt){
                nxt = to.size();
                to.push_back(vector<int>(sigma));
                end.push_back(0), pref.push_back(0);
            }
            x = nxt, pref[x]++;
        }
        end[x]++, pref[0]++;
    }

    int find(string s){
        int x = 0;
        for(auto c : s){
            x = to[x][c-norm];
            if(!x) return -1;
        }
        return x;
    }

    int count_pref(string s){
        int id = find(s);
        return id >= 0 ? pref[id] : 0;
    }
};

signed main(){
    fastio;
    trie T;
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        T.insert(s);
    }
    while(m--){
        string s; cin >> s;
        int v = T.count_pref(s);
        cout << v << endl;
    }
}