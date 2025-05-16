#include<bits/stdc++.h>
using namespace std;


int main() {
    int n,grid[400][400], cnt; cin >> n;
    int arr[] = {-1,1};

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
        cin >> grid[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int x = 0;
            for (int a = 0; a < 2; a++){
                for (int b = 0; b < 2; b++){
                    if(i+arr[a] < 0 || i+arr[a] >= n) continue;
                    if(j+arr[b] < 0 || j+arr[b] >= n) continue;
                    x+= grid[i+arr[a]][j+arr[b]];
                    if(x>2 && grid[i][j]==1) {
                        cnt = max(cnt,x);
                    }
                    
                    
                    
                }
            }
            cout << x << endl;
        }
    }
    cout << cnt << endl;
}