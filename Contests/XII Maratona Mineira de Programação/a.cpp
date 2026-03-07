#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fastio ios_base::sync_with_stdio(false),cout.tie(0),cin.tie(0)

int m(int l, int r){
    return (r - l)/2 +l;
}

signed main(){
    fastio;
    int n;
    cin >> n;

    if(n == 1) {
        cout << 1 << endl;
        return 0;
    }

    priority_queue<vector<int>> q; // tamanho, -esquerda, esquerda, direita
    q.push({n-1, -0, 0, n-1});
    vector<int> ans(n);
    ans[0] = 1;
    ans[n-1] = 2;
    int i = 3;
    while(!q.empty()){
        int l = q.top()[2];
        int r = q.top()[3];
        int meio = m(l,r);

        if(r - l <= 1){
            q.pop();
            continue;
        }

        ans[meio] = i++;
        q.pop();
        q.push({min(abs(r - m(meio,r)), abs(meio - m(meio,r))), -meio, meio, r});
        q.push({min(abs(l - m(l,meio)), abs(meio - m(l,meio))), -l, l, meio});
    }

    for(auto w:ans) cout << w << " ";
    cout << endl;

}