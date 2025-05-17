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
    string s;
    cin >> s;
    map<char,int> freq;
    for (int i = 0; i < s.size(); i++){
        char c = s[i];
        freq[c]++;
    }
    int ans = 0;
    char charans;
    for (auto u : freq){
        if (u.second > ans) {
            ans = u.second;
            charans = u.first;
        }
    }

    cout << charans << endl;

}