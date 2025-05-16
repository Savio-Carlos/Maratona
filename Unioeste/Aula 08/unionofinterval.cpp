#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
using namespace std;
#define endl '\n'
#define int long long
const int MAXL = 1e6+7;

signed main() {_
    int n;
    cin >> n;

    vector<pair<int, int>> intervals(n);
    
    // Input the intervals
    for (int i = 0; i < n; ++i) {
        cin >> intervals[i].first >> intervals[i].second;
    }
    sort(intervals.begin(), intervals.end());


    vector<pair<int, int>> merged;
    pair<int, int> current = intervals[0];


    for (int i = 1; i < n; ++i) {
        if (intervals[i].first <= current.second) {
            current.second = max(current.second, intervals[i].second);
        } else {
            merged.push_back(current);
            current = intervals[i];
        }
    }

    merged.push_back(current);
    sort(merged.begin(), merged.end());
    for (auto &u : merged){
        cout << u.first << " " << u.second << endl;
    }
}