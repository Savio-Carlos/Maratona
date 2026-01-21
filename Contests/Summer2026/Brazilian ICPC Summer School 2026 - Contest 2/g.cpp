#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define winton ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

const int MAX = 1e7+7;

int arr[MAX];

signed main(){
    winton;
    int n, k;
    cin >> n >> k;
    ll x, a, b, c;
    cin >> x >> a >> b >> c;

    arr[0] = x;    
    for (int i = 1; i < n; i++){
        arr[i] = ((arr[i-1] * a) % c + b) % c;
    }

    deque<pair<int,int>> dq; 
    int ans = 0;

    for (int i = 0; i < n; i++) {
        int cur = arr[i];

        while (!dq.empty() && dq.back().first >= cur) dq.pop_back();
        dq.push_back({cur, i});

        int left = i - k + 1;
        while (!dq.empty() && dq.front().second < left) dq.pop_front();

        if (i >= k - 1) ans ^= dq.front().first;
    }

    cout << ans << endl;
}

