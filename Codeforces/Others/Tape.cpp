#include <bits/stdc++.h>
using namespace std;
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long
#define ld long double
const int MAXS = 1e5;

signed main() {
    winton;
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), diffs;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if (i > 0){
            diffs.push_back(a[i] - a[i-1]);
        }
    }
    sort(rall(diffs));
    int tape = a[n-1] - a[0];
    for (int i = 0; i < k-1; i++){
        tape -= diffs[i];
    } 
    cout << tape+k << endl;
}