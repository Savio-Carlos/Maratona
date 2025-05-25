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

signed main(){
    winton;
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (auto &u : arr) cin >> u;
    vector<int> deltas(2*n);
    for (int i = 0; i < n; i++){
        deltas[i] = arr[i] - (i+1)*k;
    }
    for (int i = 0; i < n; i++){
        deltas[i+n] = arr[i] - (i+1+n)*k;
    }
    //for (auto y : deltas) cout << y << " ";
    stack<int> st;
    vector<int>temp(2*n);
    for (int i = 2*n-1; i >= 0; i--){
        while(!st.empty() && deltas[st.top()] >= deltas[i]){
            st.pop();
        }
        temp[i] = st.empty()? -1 : st.top();
        st.emplace(i);
    }
    vector<int> ans(n, 1);
    for (int i = 0; i < n; ++i) {
        if (temp[i] == -1){
            ans[i] = i+1;
        }
        else{
            ans[i] = (temp[i]%n)+1;
        }
    }
    for (auto u : ans) cout << u << " ";
}