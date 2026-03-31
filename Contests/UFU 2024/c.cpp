#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int long long
#define ld long double
#define endl '\n'

#define winton ios_base::sync_with_stdio(false),cin.tie(0)

const int MAX = 1e6+7;

int fastexpo(int base, int exp){
    int res = 1;
    while (exp) {
        if(exp&1) res = res * base;
        base = base * base;
        exp >>= 1;
    }
    return res;
}

int a[MAX];
vector<int> graph[MAX];
int ans = -1e9;

void dfs(int v, int p, int sum){
    sum += a[v];
    if (graph[v].empty()){
        ans = max(ans, sum);
    }
    for (auto u : graph[v]){
        if (u == p) continue;
        dfs(u,v, sum);
    }

}

signed main(){
    winton;
    int n, b, l;
    cin >> n >> b >> l;

    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    int nivel = 0;
    int diff = 1;
    queue<tuple<int,int,int>> q;
    q.push({1,0,1});//vertice, nivel

    while(!q.empty()){
        auto [v, nivel, diff] = q.front();
        q.pop();
        if (nivel == l-1) continue;

        for (int i = 1; i <= b; i++){
            graph[v].push_back(v+(i*diff));
            q.push({v+(i*diff), nivel+1, diff*b});
        }
    }
    // for (int i = 1; i <= n; i++){
    //     cout << "pai: " << i << ": " << endl;
    //     for (auto u : graph[i]) cout << u << " ";
    //     cout << endl;
    // }
    dfs(1, 0, 0);
    cout << ans << endl;

}