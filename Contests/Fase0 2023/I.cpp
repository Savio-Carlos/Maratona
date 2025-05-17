#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAXN = 2e5+7;

signed main(){
    winton;
    map<int,vector<int>> mp;
    mp[1] = {5,2};
    mp[2] = {1,3,5,6};
    mp[3] = {2,4,6,7};
    mp[4] = {3,7};
    mp[5] = {1,2,6,8};
    mp[6] = {2,3,5,7,8,9};
    mp[7] = {3,4,6,9};
    mp[8] = {5,6,9,10};
    mp[9] = {6,7,8,10};
    mp[10] = {8,9};
    vector<int> a(10);
    for (auto &u : a)cin>>u;
    int best = 11;
    vector<int> best_ans;
    for (int i = 0; i < (1<<10); i++){
        vector<int> temp = a;
        vector<int> ans;
        for (int j = 0; j < 10; j++){
            int pos = 1<<j;
            if (i&pos) {
                ans.push_back(j+1);
                for (auto u : mp[j+1]){
                    temp[u-1] = !temp[u-1];
                }
            }   
        }
        if (accumulate(temp.begin(), temp.end(), 0) == 10){
            if ((int)ans.size() < best || ((int)ans.size() == best && ans < best_ans)) {
                best = ans.size();
                best_ans = ans;
            }
        }
    }
    if (best == 11) cout << "-1" << endl;
    else {
        cout << best << endl;
        for (int i = 0; i < (int)best_ans.size(); i++) {
            if (i) cout << ' ';
            cout << best_ans[i];
        }
        if (!best_ans.empty()) cout << endl;
    }
}