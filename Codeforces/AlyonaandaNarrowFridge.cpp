#include <bits/stdc++.h>
using namespace std;
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long
#define ld long double
const int MOD = 1e9+7;

int h;

bool solve(int k, vector<int> a){
    sort(a.begin(), a.begin() + k, greater<int>());
    int b = 0;
    for (int i = 0; i < k; i+=2){
        b+= a[i];
    }
    return (b <= h);
}

signed main() {
    winton;
    int n;
    cin >> n >> h;
    vector<int> bottles(n);
    for (int &i : bottles) cin >> i;

    int l = 0, r = n, ans = -1;
    while (l <= r){
        int mid = l + (r-l)/2;
        bool possible = solve(mid, bottles);

        if (possible){
            ans = mid;
            l = mid+1;
        }
        else {
            r = mid -1;
        }
    }
    cout << ans << endl;
}