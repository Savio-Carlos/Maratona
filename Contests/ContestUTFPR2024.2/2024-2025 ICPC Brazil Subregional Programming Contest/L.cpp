#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAX = 34;
int bits[MAX];
signed main(){
    winton;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        //for (auto u : bits) cout << u << " ";
        for (int j = 0; j < 33; j++){
            if (a & (1<<j)) bits[j]++;
        }
    }
    vector<int> ans;
    //for (auto u : bits) cout << u << " ";
    while (n--){
        int cur = 0;
        for (int i = 0; i < 33; i++){
            if (bits[i] > 0){
                cur |= (1<<(i));
                bits[i]--;
            } 
        }
        ans.push_back(cur);
    }
    for (auto u : ans) cout << u << " ";
}