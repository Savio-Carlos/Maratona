#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define endl '\n'

#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

signed main(){
    fastio;
    int n;
    cin >> n;
    priority_queue<int> pq;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;

        if(s == "/"){
            cout << pq.top() + 10 - (pq.top() % 10) << endl;
            continue;
        }

        int num = stoi(s);
        pq.push(num);
        cout << num << endl;
    }
}