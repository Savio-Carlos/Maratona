#include <bits/stdc++.h>
using namespace std;
const int MAX = 101;

int grid[MAX][MAX];

int main(){
    int n, mx = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        mx = max(mx,a[i]);
    }
    for (int i = 0; i < n; i++){
        int cur = a[i];
        for (int j = mx; j >= mx-cur; j--){
            grid[j][i] = 1;
        }
    }
    for (int i = 0; i < mx; i++){
        for (int j = 0; j < n; j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    } 
}