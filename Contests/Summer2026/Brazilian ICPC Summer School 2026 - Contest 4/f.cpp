#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define all(x) x.begin(), x.end()
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)

signed main(){
    winton;
    string s;
    cin >> s;
    vector<int> freq(26, 0);

    for (auto c : s) freq[c - 'A']++;

    int e = 0;
    int m = -1;
    for (int i = 0; i < 26; i++){
        if (freq[i]&1){
            e++;
            m = i;
        } 
    }

    if (e > 1){
        cout << "NO SOLUTION" << endl;
        return 0;
    } 

    string ans = ""; 
    for (int i = 0; i < 26; i++){
        int cnt = freq[i]/2;
        while (cnt--) ans += 'A' + i;
    }
    string sna = ans;
    reverse(all(sna));
    cout << ans;
    if (m != -1) cout << (char)('A' + m);
    cout << sna << endl;
}