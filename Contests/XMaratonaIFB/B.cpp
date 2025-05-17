#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAX = 7;

int n, grid[MAX][MAX];

bool brute(int linha, int coluna) {
    if (linha == n) {//chegou no final
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
        return true;
    }

    if (coluna == n) return brute(linha + 1, 0);//final das rows
    if (grid[linha][coluna] != 0) return brute(linha, coluna + 1);

    for (int k = 1; k <= n; k++) {
        bool pode = true;//verificar se ja existe o k nessa linha ou coluna, como n <= 7 entao e possivel verificar tudo
        for (int i = 0; i < n; i++){
            if (grid[linha][i] == k) pode = false;
            if (grid[i][coluna] == k) pode = false;
        }
        if (pode) {
            grid[linha][coluna] = k;
            if (brute(linha, coluna + 1)) return true;
            grid[linha][coluna] = 0;
        }
    }
    return false;
}

signed main() {
    winton;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>grid[i][j];
        }
    }
    if (!brute(0,0)) cout << "-1" << endl;
}