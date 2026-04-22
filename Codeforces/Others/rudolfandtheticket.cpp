#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int tt;
    cin >> tt;
    while (tt--){
        int n, m, k, ans = 0;
        cin >> n >> m >> k;
        vector<int> esq(n);
        vector<int> dir(m);

        for (int i = 0; i < n; i++){
            cin >> esq[i];
        }
        for (int j = 0; j < m; j++){
                cin >> dir[j];     
        }
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if ((esq[i]+dir[j])<=k) ans++;
            }
        }

        cout << ans << endl;
    }
}