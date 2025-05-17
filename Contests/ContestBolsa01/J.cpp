#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long
#define vi vector<int>
#define pb push_back
const int MAXL = 1e9+7;

signed main(){_
    int n, k; cin >> n >> k;
    vi dishes (n);
    for (auto &i : dishes) cin >>i;
    map<int, int> diff;
    int l = 0, r = n-1; 
    pair<int,int> ans;
    int size = 0;
    for (int r = 0; r < n; r++) {
        diff[dishes[r]]++;
        while (diff.size() > k) {
            diff[dishes[l]]--;
            if (diff[dishes[l]] == 0) {
                diff.erase(dishes[l]);
            }
            l++;
        }
        if (r - l + 1 > size) {
            size = r - l + 1;
            ans.first = l;
            ans.second = r;
        }
    }
    cout << size << endl;
    cout << ans.first+1 << " " << ans.second+1 << endl;
}


