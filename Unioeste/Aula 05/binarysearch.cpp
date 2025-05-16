#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

int main(){
    vector<int> arr;
    ll n, min, max, ans, q;
    cin >> n >> q;
    arr.resize(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        //cout << arr[i];
    }
    min = 0;
    max = n;
    while (q--){
        int c;
        cin >> c;
        while (arr[ans] != c){
            ans = (min + max)/2;
            cout << "ans = " << ans << " " << endl;
            if (arr[ans] > c){
                max = max/2;
                cout << "max = " << max << " "; 
            }
            else if (arr[ans] < c) {
                min = ans;
                cout << "min = " << min << " ";
            }
        }
        cout << endl << ans << endl;

    }
    // 20  0-100 50 max = 50; 25 max = 25; 12.5; min = 12.5; 17.25  min = 17.25



}