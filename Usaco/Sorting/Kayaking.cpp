#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long
const int MAXL = 1e5+7;

signed main() {_
    int n; cin >> n;
    n*=2;
    int ans = LLONG_MAX;
    vector<int> people (n);
    for (auto &i : people) cin >> i;
    sort(all(people));
    for (int i = 0; i < n; i++){
        for (int j = i; j < n; j++){
            vector<int> temp = people;
            temp.erase(temp.begin() + i);
            temp.erase(temp.begin() + j);
            int diff = 0;
           
            for (int k = 1; k < n; k+=2){
                diff += abs(temp[k]-temp[k-1]);
            }

            ans = min (ans, diff);
        }
    }
    cout << ans << endl;
}