#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAXN = 1e2+7;

signed main(){  
    winton;
    int n, m;
    cin >> n >> m;
    map<int,int> visited;
    vector<int>grid(n*m,0);
    int st = 0;
    for (int i = 0; i < n*m; i++){
        cin >> grid[i];
        visited[grid[i]]++;
        if (visited[grid[i]] == 2)st = grid[i];
    }
    int *it = find(grid.begin(), grid.end(), st);
    cout << st << " <st : it> " << it << endl;
    if (st){
        for (int i = it+1; i < n*m; i++){
            if (grid[i] >= st && visited[grid[i]] > 1){
                grid[i]++;
                visited[grid[i]]++;
            }
        }    
    }
    for (int i = 0; i < n*m; i++){
        cout << grid[i] << " ";
    }
}