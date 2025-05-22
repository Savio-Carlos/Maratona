#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAX = 1e5+7;

signed main(){
    winton;
    int n, d;
    cin >> n >> d;
    vector<pair<int,int>> pontos;
    for (int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        pontos.push_back({a,b});
    }
    vector<int> pfx(n+1), sfx(n+1);
    sort(all(pontos));

    int cur = 0;
    for(int i = 0, j = 0; i < n; i++){
        cur += pontos[i].second;
        while(pontos[i].first - pontos[j].first > d){
            cur -= pontos[j].second;
            j++;
        }
        if (i) pfx[i] =max(pfx[i-1], cur);
        else pfx[i] = cur;
    }
    cur = 0;
    for(int i = n-1, j = n-1; i >= 0; i--){
        cur += pontos[i].second;
        while(pontos[j].first - pontos[i].first > d){
            cur -= pontos[j].second;
            j--;
        }
        if (i) sfx[i] = max(sfx[i+1], cur);
        else sfx[i] = cur;
    }
    int ans = 0;
    for (int i = 0; i < n; i++){
        ans = max(ans, pfx[i] + sfx[i+1]);
        //cout << i << " " << n-i << " " << ans << endl;
    }
    //ans = max()
    // for (auto u : pfx) cout << u << " ";
    // cout << endl;
    // for (auto u : sfx) cout << u << " ";
    // cout << endl;
    cout << ans << endl;
}    