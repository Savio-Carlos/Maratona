#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int t;
    cin >> t;
    while (t--){
        int k, n, robin = 0, ans = 0;
        cin >> n >> k;
        vector<int> arr(n);

        for (int i = 0; i < n; i++){
            cin >> arr[i];
        }
        for (int i = 0; i < n; i++){
            if (arr[i] >= k){
                robin += arr[i];
                arr[i] = 0;
            }
            else if (arr[i] == 0 && robin > 0){
                robin--;
                arr[i] = 1;
                ans++;
            }
        }
        cout << ans << endl;
    }
}