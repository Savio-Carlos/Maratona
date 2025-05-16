#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, sum=0, aux=0; cin >> n; 
    int grid[n][n];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
        aux = 0;
            for (int k = 0; k < n; k++){
                aux += grid[i][k];
            }
        
            for (int k = 0; k < n; k++){
                aux += grid[k][j];
            }
            
            aux -= 2*(grid[i][j]);
           
        sum = max(aux, sum);
        }
    }

    cout << sum << endl;

    return 0;
}