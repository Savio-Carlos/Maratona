#include <bits/stdc++.h>
using namespace std;
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long
#define ld long double
const int INF = 1e9+7;

signed main() {
    winton
    int n, k;
    cin >> n >> k;
    vector<pair<int,int>> clients;
    for (int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        clients.push_back({a,b+a});
    }
    vector<pair<int,int>> sweep;
    int c = k;
    priority_queue<int> pq;//fazer o vetor de sweep line e depois usar os pares {e,1}, {s,-1} para contar os simultaneos
    for(int i = 0; i < clients.size(); i++){
        if (c > 0){
            sweep.push_back({clients[i].first, clients[i].second});
            pq.push(-clients[i].second);
            c--;
        }
        else {
            int fend = - pq.top();
            pq.pop();
            //cout << fend << endl;
            if (clients[i].first <= fend){
                int nend = fend + (clients[i].second-clients[i].first);
                sweep.push_back({clients[i].first, nend});
                pq.push(-nend);
            }
            else {
                sweep.push_back({clients[i].first, clients[i].second});
                pq.push(-clients[i].second);
            }
        }
    }
    vector<pair<int,int>> stay;
    stay.push_back({0,0});
    for (auto [u,v] : sweep){
        stay.push_back({u,1});
        stay.push_back({v,-1});
    }
    stay.push_back({INF,0});
    sort(all(stay));
    int ans = 0, cur = 0;
    for (auto [t,i] : stay){
        cur += i;
        ans = max(ans,cur);
    }
    cout << ans << endl;
}
