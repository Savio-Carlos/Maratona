
#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long
const int MAXL = 1e9+7;

signed main() {_
    int t; cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for (auto &i : arr) cin >> i;

        pair<pair<int,int>,int> maxInverter = {{0,0},0};

        for (int i = 0; i < n; i++){//achar o maior inversor
            int cur = arr[i];
            int cnt = 0;
            int final = i;
            for (int j = i+1; j < n; j++){
                if (arr[j] < cur) {
                    cnt--;
                }
                else if (arr[j] > cur){
                    cnt++;
                }
                if (cnt < maxInverter.second){
                    maxInverter.second = cnt;
                    maxInverter.first.first = i;
                    maxInverter.first.second = j;
                }
            }

        }

        cout << maxInverter.first.first+1 << " " << maxInverter.first.second+1 << endl;

        
    }
}
