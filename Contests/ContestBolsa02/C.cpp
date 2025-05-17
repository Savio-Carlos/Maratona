#include <bits/stdc++.h>
using namespace std;
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long
#define ld long double
const int MAXS = 1e5 + 7;

signed main() {
    winton
    int n;
    cin >> n;
    vector<pair<int,pair<int,int>>> cards(n);
    for (int i = 0; i < n; i++){
        cin >> cards[i].first >> cards[i].second.first;
        cards[i].second.second = i+1;
    }
    vector<pair<int,int>> temp(n);
    for (int i = 0; i < n; i++){
        temp[i].first = cards[i].first;
        temp[i].second = cards[i].second.first;

    }
    sort(all(temp));
    sort(all(cards));
    priority_queue<pair<int,int>> pq;
    pq.push({temp[0].second, 0});
    for (int i = 1; i < n; i++){
        while (!pq.empty() && temp[i].second < pq.top().first){
            pair<int,int> cur = pq.top();
            if (temp[i].second < cur.first){
                temp[cur.second].first = 0;
                temp[cur.second].second = 0;
                pq.pop();
            }
        }
        pq.push({temp[i].second, i});
    }
    set<int> ans;
    for (int i = 0; i < n; i++){
        if (temp[i].first != 0 && temp[i].second != 0){
            ans.insert(cards[i].second.second);
        }
    }
    cout << ans.size() << endl;
    for (auto i : ans) cout << i << " ";
}