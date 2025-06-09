#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define minecraft ios_base::sync_with_stdio(0); cin.tie(0)
const ll MOD = 1e9+7;
const ll INF = 2e5;

#define int long long

signed main(){
    minecraft;
    int n,m,k;
    cin>>n>>m;

    vector<bool>visited(1e5+10, false);
    vector<bool>ans(m+1, 0);
    queue<int> q;
    stack<int>s;
    // Le o primeiro
    cin >> k;
    for(int i = 0; i < k; i++){
        int aux;
        cin >> aux;
        s.push(aux);
    }

    

    for(int i = 0; i < n-1; i++){
        while(!s.empty()){
            visited[s.top()] = true;
            s.pop();
        };
        cin >> k;
        for(int i = 0; i < k; i++){
            int aux;
            cin >> aux;
            q.push(aux);
        }
        while(!q.empty()){
            if(!visited[q.front()]){
                s.push(q.front());
            } else {
                while(!s.empty()){
                    ans[s.top()] = 1;
                    //cout <<"deba" << s.top() << endl;
                    s.pop();
                }
            }
            q.pop();
        }

    }

    for(int i = 1; i <= m; i++) cout << ans[i] << " ";
    cout << endl;
    return 0;

}