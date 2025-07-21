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
const int INF = LLONG_MAX;

vector<int> manacher_odd(string s) {
    int n = s.size();
    s = "$" + s + "^";
    vector<int> p(n + 2);
    int l = 0, r = 1;
    for(int i = 1; i <= n; i++) {
        p[i] = min(r - i, p[l + (r - i)]);
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if(i + p[i] > r) {
            l = i - p[i];
            r = i + p[i];
        }
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
}

vector<int> manacher(string s) {
    string t;
    for(auto c: s) {
        t += string("#") + c;
    }
    auto res = manacher_odd(t + "#");
    return res;
}

signed main() {
    winton;
    string s;
    cin >> s;
    vector<int> mnc = manacher(s);
    //for (auto u : mnc) cout << u << " ";
    vector<pair<int,int>> palindromes;
    for (int i = 0; i < mnc.size(); i++){
        if (mnc[i]-1 > 0){
            palindromes.push_back({mnc[i]-1,i});
        }
    }
    sort(rall(palindromes));
    string best = "-1";
    map<string,int> cnt;
    for (auto &[size, centro] : palindromes){
        if (size < best.size() && best != "-1") break;
        // debug(centro);
        // debug(size);
        string pos;
        int st = ((centro - size)/2);
        pos = s.substr(st, size);
        // debug(pos);

        bool repete = false;
        int pos_before = s.find(pos, 0);
        if (pos_before != string::npos && pos_before + size <= st) {
            repete = true;
        }

        if (!repete) {
            int pos_after = s.find(pos, st + size);
            if (pos_after != string::npos) {
                repete = true;
            }
        }

        if (repete) {
            if (pos.size() > best.size()) {
                best = pos;
            } else if (pos.size() == best.size() || best == "-1") {
                if (pos < best || best == "-1") {
                    best = pos;
                }
            }
        }
    }
    cout << best << endl;
}