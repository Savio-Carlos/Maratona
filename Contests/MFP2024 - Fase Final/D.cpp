#include <bits/stdc++.h>
using namespace std;
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long
#define ld long double
const int MAXS = 1e5;

bool visited[6];
vector<int> somas;
int grid[6][6];

void search(int r, int soma){
    if (r == 6){
        somas.push_back(soma);
        return;
    }
    for (int c = 0; c < 6; c++) {
        if (!visited[c]) {
            visited[c] = true;
            search(r + 1, soma + grid[r][c]);
            visited[c] = false;
        }
    }
}

signed main() {
    winton
    int n = 6;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }

    
    search(0,0);
    
    cout << *max_element(all(somas)) << endl;
}
