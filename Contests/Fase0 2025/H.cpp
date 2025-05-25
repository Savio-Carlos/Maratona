#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAX = 2e5+7;
const int INF = INT_MAX;

vector<string> palindromes;
int n;  
int size;

void build(string s){
    string cur = s;
    //cout << cur << endl;
    if (cur.size() > 32) return;
    palindromes.push_back(cur);
    if (cur.size()%2 == 0){
        string t = cur;
        string t2 = cur;
        int pos = cur.size()/2;
        t.insert(t.begin() + pos,'0');
        t2.insert(t2.begin() + pos,'1');
        build(t);
        build(t2);
    }
    else {
        int pos = cur.size()/2;
        char ad = cur[pos];
        string t = cur;
        t.insert(t.begin()+pos,ad);
        build(t);
    }
}
signed main(){
    winton;
    cin >> n;
    string s1 = "1";
    string s0 = "0";
    build(s1);
    //build(s0);
    int ans;
    for (auto u : palindromes){
        int cur = 0;
        for (char c : u) {
            cur <<= 1; 
            if (c == '1') {
                cur |= 1;
            }
        }
        if (cur <= n){
            ans = cur;
            ans = max(ans,cur);
        }
    }
    cout << ans << endl;
}