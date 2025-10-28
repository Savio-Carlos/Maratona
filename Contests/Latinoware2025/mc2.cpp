#include <bits/stdc++.h>
#define int long long
#define ld long double
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

map<char,pair<int, int>> mp;
map<int, int> val1;

//pode ser 0 ou 1 indexado tem q testarrr
void setup(){
    mp['I'] = {1, 1};
    mp['V'] = {2, 5};
    mp['X'] = {3, 10};
    mp['L'] = {4, 50};
    mp['C'] = {5, 100};
    mp['D'] = {6, 500};
    mp['M'] = {7, 1000};
}

void setup2(){
    val1[1] = {1};
    val1[2] = {5};
    val1[3] = {10};
    val1[4] = {50};
    val1[5] = {100};
    val1[6] = {500};
    val1[7] = {1000};
}


signed main(){
    // fastio;
    setup();
    setup2();
    int t;
    cin >> t;
    while (t--){
        string s;
        cin >> s;
        vector<int> cnt(8, 0);
        for (auto c : s){
            cnt[mp[c].first]++;
        }
        int n = s.size();
        int ans = 0;
        for (int i = n-1; i >= 0; i--){
            auto [idx, value] = mp[s[i]];
            if (cnt[idx] <= 0) continue;
            //cout << idx << " value " << value << endl;
            int add = value;
            for(int j = 1; j < idx; j++){
                if(cnt[j] <= 0) continue;
                add -= (cnt[j]*val1[j]);
                cnt[j] = 0;
            }
            cnt[idx]--;
            ans += add;
        }
        cout << ans << endl;
    }
}