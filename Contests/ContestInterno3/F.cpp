#include <bits/stdc++.h>
using namespace std;
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long
#define ld long double
const int MOD = 1e9+7;

signed main() {
    winton;
    string s;
    cin >> s;
    string s1 = "", s2 = "";

    for (int i = 0; i < s.size(); i++){
        if (s[i] != 'a') s1 += s[i]; 
    }
    bool possible = true;
    int metade = s1.size()/2;
    //cout << s1 << endl;
    for (int i = 0; i < metade; i++){
        s2+=s1[i];
    }
    //cout << s2 << endl;
    int start = s.size() - s2.size();
    string s3 = s.substr(start, s2.size());
    //cout << s3 << endl;
    if (s2 == s3 && s1.size()%2 == 0){
        for (int i = 0; i < start; i++){
            cout << s[i];
        }
        cout << endl;
    }
    else cout << ":(" << endl;
    //brother me da um ac ai
}