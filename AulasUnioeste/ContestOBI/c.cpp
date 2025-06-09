#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAX = 500;
const int INF = INT_MAX;

int car[MAX], tot[MAX];

signed main(){
    winton;
    int n, m, c;
    cin >> n >> c >> m;
    for (int i = 0; i < c; i++){
        int a;
        cin >> a;
        car[a] = 1; 
    }
    for (int i = 0; i < m; i++){
        int a;
        cin >> a;
        tot[a] = 1;
    }
    int ans = 0;
    for (int i = 0; i < MAX; i++){
        if (car[i] && tot[i])ans++;
    }
    cout << c - ans << endl;
}
