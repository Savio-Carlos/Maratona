#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
using namespace std;
#define endl '\n'
#define int long long
const int MAXL = 1e6+7;

vector<int> impares;
vector<int> visited (MAXL, 0);

signed main() {_  
    int n;
    cin >> n;
    int nimpars = 0;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a % 2 != 0) {
            impares.push_back(i);
            nimpars++;
        }
    }

    int a, b;
    cin >> a >> b;
    int menor = min(a, b);
    if (impares.empty()) {
        cout << "0" << endl;
        return 0;
    }
    impares.push_back(impares[0] + n);
    if (nimpars % 2 != 0) {
        cout << "-1" << endl;
        return 0;
    }

    int ans = 0;
    int ans1 = 0;
    int ans2 = 0;

    for (int i = 0, j = 1; j < impares.size() - 1; i += 2, j += 2) {
        ans1 += abs(impares[i] - impares[i+1]);
        ans2 += abs(impares[j] - impares[j+1]);
    }

    ans = min(ans1, ans2);
    cout << ans * menor << endl;
}
/*
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
using namespace std;
#define endl '\n'
#define int long long
const int MAXL = 1e6+7; 

vector<pair<int,pair<int,int>>> pares;
 vector<int> impares;
 vector<int> visited (MAXL, 0);

signed main() {_
    int n;
    cin >> n;
    int nimpars = 0;
   
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        if (a %2 != 0) {
            impares.push_back(i);
            nimpars++;
        }
    }
    int a, b;
    cin >> a >> b;
    int menor = min(a,b);
    if (nimpars %2 != 0) {
        cout << "-1" << endl;
        return 0;
    }
    
    for (int i = 0 ; i < impares.size()-1; i++){
        int dist = abs(impares[i] - impares[i+1]);
        pares.push_back({dist,{impares[i], impares[i+1]}});
    }
    pares.push_back({abs(n-impares[impares.size()-1] + impares[0]),{impares[0],impares[impares.size()-1]}});
    
    sort(pares.begin(), pares.end(), greater<pair<int,pair<int,int>>>());
    int ans = 0;
    for (auto u : pares){
        int d = u.first;
        int p = u.second.first;
        int s = u.second.second;
        if (visited[p] < 2 || visited[s] < 2){
            visited[p]++;
            visited[s]++;
        }
        cout << d << " " << p << " " << s << endl;
        if (visited[p] == 2 ){
            ans+=d;
            visited[s] = 3;
             //cout << "n adicionado " << p << endl;
            continue;
        }
        else if (visited[s] == 2){
            ans+=d;
            visited[p] = 3;
            //cout << "n adicionado " << s << endl;
            continue;
        }
        
       // cout << visited[p] << " " << visited[s] << endl;
        
        
    }
    cout << ans*menor << endl;
}
*/

/*
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
using namespace std;
#define endl '\n'
#define int long long
const int MAXL = 1e6+7;

vector<int> impares;
vector<int> visited (MAXL, 0);

signed main() {_
    int n;
    cin >> n;
    int nimpars = 0;
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        if (a %2 != 0) {
            impares.push_back(i);
            nimpars++;
        }
    }
   
    int a, b;
    cin >> a >> b;
    int menor = min(a,b);
    if (nimpars %2 != 0) {
        cout << "-1" << endl;
        return 0;
    }
    int ans = 0;
    for (int i = 0; i < impares.size()-1; i++){
        if (visited[impares[i]]) continue;
        int p = i+1, a = i-1;
        if (i == 0) a = impares.size()-1;
        //cout << impares[i] << " " << impares[p] << " " << impares[a];

        int f = abs(impares[i]-impares[p]);
        int s = abs(n-impares[a]+impares[i]);

        if (f <= s && !visited[impares[p]]){
            ans += f;
            visited[impares[p]] = true;
          //  cout << " ++= " << f << endl;
        }
        else {
            ans+= s;
            visited[impares[a]] = true;
            //cout << " += " << s << endl;
        }
        visited[i] = true;
    }
    cout << ans*menor << endl;
}
*/