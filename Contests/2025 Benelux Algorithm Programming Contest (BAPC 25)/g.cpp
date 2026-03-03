#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false),cout.tie(0),cin.tie(0) 



signed main(){
    fastio; 
    string s;
    cin >> s;
    int n;
    cin >> n;

    set<string> st;
    for(int i = 0; i < n; i++){
        string aux;
        cin >> aux;
        st.insert(aux);
    }

    queue<int> q;
    q.push(0);
    bool found = false;
    vector<bool> visitado(s.size()+1, false);
    while(!q.empty()){
        int inicio = q.front();

        if(inicio == s.size()){
            found = true;
            break;
        }

        if(inicio > s.size()) continue;

        string aux = "";

        int i = q.front();
        for(; i < s.size() && i < inicio + 5; i++){
            aux += s[i];
        }

        for(; i < s.size() && i < inicio + 10; i++){
            aux += s[i];
            if(st.find(aux) != st.end()){
                if(!visitado[i+1]) q.push(i+1);
                visitado[i+1] = true;
            }
        }

        q.pop();
    }
    cout << (found ? "yes":"no") << endl;
}