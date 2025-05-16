#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
using namespace std;
#define endl '\n'
#define int long long
const int MAXL = LLONG_MAX;

signed main(){_
    int t; cin >> t;
    while(t--){
        int n;
        char c;
        cin >> n >> c;
        string s; cin >> s;
        int ans = 0;
        vector<int> greens;

        for (int i = 0; i < n; i++){
            if (s[i] == 'g' && s[i-1] != 'g') greens.push_back(i);
        }
        sort(greens.begin(),greens.end());
        //for (auto &u : greens) cout << "verdinho no " << u << endl;

        for (int i = 0; i < n; i++){
            if (s[i] == c){
                    auto prox = upper_bound(greens.begin(),greens.end(), i);
                    int idx = *prox;
                    if (prox == greens.end()) idx = greens[0];

                    int temp;
                    //cout << "i: " << i << " idx: " << idx << endl;
                    if (i > idx){
                        temp = (idx+n-i);
                    }
                    else temp = idx - i;
                    ans = max(ans,temp); 
                    //cout << "cur ans: "<<ans << endl;
            }
        }
        if (c == 'g'){
            cout << "0" << endl;
        }
        else cout << ans << endl;
    }
}