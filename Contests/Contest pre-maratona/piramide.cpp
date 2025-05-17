#include <iostream>
using namespace std;

int main(){
    int n, a=0, b=0, layer = 1; 
    cin >> n;
    int grid[n][n];
    int aux = n/2;
    b=n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            grid[i][j] = 0;
            
        }
    }

    while(aux>=0){
        for (int i = a; i < b; i++){
            for (int j = a; j < b; j++){
            grid[i][j] += layer;
            
            }
        }
        a++;
        b--;
        aux--;
    }
    

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
        cout << grid[i][j] << " ";
        }  
        cout << endl;
    }

    return 0;
}