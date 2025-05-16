#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
using namespace std;
#define endl '\n'
#define int long long
const int MAXL = 1e6+7;

signed main (){_
    int n, s;
    cin >> n >> s;
    double sum = 0;
    priority_queue<double> pq;
    for (int i = 0; i < n; i++){
        int a; cin >> a;
        pq.emplace(a);
        sum += a;
    }
   
    int ans = 0;
    while(sum > s){
        double x = pq.top();
        sum -= ceil(x/2);
        ans++;
        pq.pop();
        pq.emplace(floor(x/2));
    }
    cout << ans << endl;
}