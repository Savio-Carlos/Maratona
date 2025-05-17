#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)

signed main () {
    winton;
    int n, m;
    cin >> n >> m;
    vector<bool> mark(m+1);
    for (int i = 0; i < m; i++){
        int a; cin >> a;
        mark[a] = true;
    }
    stack<int> st;
    for (int i = 1; i <= n; i++){
        st.emplace(i);
        if (!mark[i]){
            while (!st.empty()){
                cout << st.top() << " ";
                st.pop();
            }
        }
    }
}