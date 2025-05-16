#include <bits/stdc++.h>

using namespace std;

int main(){
    int grid[5][5], x, y, dist, i = 0, j = 0;
  

    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){
            cin >> grid[i][j];
            if (grid[i][j] == 1){

                cout << "x: " << i << ", y: " << j << endl;
                dist = abs(2 - i) + abs(2 - j);
                cout << dist << endl;
                return 0;
            }
        }
    }
    return 0;

}