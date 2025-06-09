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

int meio(int a, int b, int c){
    vector<int> haha(3);
    haha[0] = a; 
    haha[1] = b; 
    haha[2] = c; 
    sort(all(haha));
    return haha[1];
}

signed main(){
    winton;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int ans = 2;
        int a1 = 1, a2 = 1, a3 = 0;
        while (a1 != n || a2!=n || a3!=n){
            int mid = meio(a1,a2,a3);
            int mn = min({a1,a2,a3});
            int novo = mid*2 + mid%2;
            if (a1 == mn){
                a1 = min(novo,n);
            }
            else if (a2 == mn){
                a2 = min(novo,n);
            }
            else {
                a3 = min(novo,n);
            }
            ans++;
        }
        cout << ans << endl;
    }
}