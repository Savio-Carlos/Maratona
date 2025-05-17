#include <bits/stdc++.h>
using namespace std;

int querry(int a, int b, int arr[]){
    int sum = 0;
    a--, b--;
    for (; a<=b; a++){
        sum+= arr[a];
    }
    return sum;
}

int main(){
    int n, q, a, b; cin >> n >> q;
    int arr[n];

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    while(q--){
        cin >> a >> b;
        cout << querry(a, b ,arr) << endl;
    }

    return 0;
 }