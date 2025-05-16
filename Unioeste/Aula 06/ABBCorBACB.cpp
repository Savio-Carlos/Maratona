#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
using namespace std;
#define endl '\n'
#define int long long

signed main() {_
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.length();
        int cnt = 0, ans = 0, i = 0;
        if (s[0] == 'B' || s[n-1] == 'B'){
            for (int i = 0; i < n; i++){
                if (s[i] == 'A') ans++;
            }
            cout << ans << endl;
            continue;
        }
        else {
            int cur = 0;
            vector<int> sequences;
            for (int i = 0; i < n; i++){
                if (s[i] == 'A') cur++;
                else {
                    if (cur != 0) sequences.push_back(cur);
                    cur = 0;
                }
            }
            if (cur != 0) sequences.push_back(cur);
            sort(sequences.begin(),sequences.end(), greater<int>());
            if(sequences.empty()) {cout << 0 << endl; continue;}

            for (int i = 1; i < sequences.size(); i++){
                ans+=sequences[i];
            }
            cout << ans << endl;
        }
    }
}
