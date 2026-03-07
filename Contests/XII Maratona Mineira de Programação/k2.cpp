#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fastio ios_base::sync_with_stdio(false),cout.tie(0),cin.tie(0)

signed main(){
    fastio;
    int n;
    cin >> n;
    vector<int> ans;
    int momento = 0;
    map<pair<int,int>, int> visited;
    for (int i = 0; i < n; i++){
        int inicio, velocidade;
        cin >> inicio >> velocidade;
        int posatual = inicio + (velocidade * momento);
        if (visited[{momento,posatual}] == 1) continue;
        visited[{momento,posatual}] = 1;
        ans.push_back(posatual);
        momento++;
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << " " << i << endl;
    }
}