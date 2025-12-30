#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld double
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

ld round(ld x){
    string fix = to_string(x);
    for (int i = 0;i < fix.size(); i++){
        if (fix[i] == '.'){
            if(i+2 <= fix.size()-1){
                if (fix[i+2] == '2' || fix[i+2] == '1') fix[i+2] = '0';
                if (fix[i+2] == '7' || fix[i+2] == '6') fix[i+2] = '5';
            }
        }
    }
    return stod(fix); 
}

signed main(){
    fastio;
    int n;
    cin >> n;
    ld sum = 0.0;
    int t = 0, q = 0;
    queue<string> tres;
    queue<string> quatro;
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
            if (s[s.size()-1] == '2' || s[s.size()-1] == '1') s[s.size()-1] = '0';
            if (s[s.size()-1] == '7' || s[s.size()-1] == '6') s[s.size()-1] = '5';

            if ((s[s.size()-1]-'0') % 5 == 3 || (s[s.size()-1]-'0') % 5 == 4){
                if (s[s.size()-1] == '9' || s[s.size()-1] == '4') quatro.push(s);
                if (s[s.size()-1] == '8' || s[s.size()-1] == '3') tres.push(s);
                continue;
            }
        
        sum += stod(s);
        // cout << "sum i:" << sum << " " << s << " stod s: " <<stod(s)  << endl;
 
    }
    
    cout << fixed << setprecision(2);
    while (tres.size() && quatro.size()){
        string t = tres.front();
        tres.pop();
        string q = quatro.front();
        quatro.pop();

        ld add = stod(t) + stod(q);
        sum += round(add);
    }
    while (tres.size() > 1){
        string t = tres.front();
        tres.pop();
        string t2 = tres.front();
        tres.pop();
        ld add = stod(t) + stod(t2);
        sum += round(add);
    }
    while (quatro.size() > 2){
        string q = quatro.front();
        quatro.pop();
        string q2 = quatro.front();
        quatro.pop();
        string q3 = quatro.front();
        quatro.pop();
        ld add = stod(q) + stod(q2) + stod(q3);
        sum += round(add);
    }
    while(tres.size()){
        string add = tres.front();
        tres.pop();
        sum += stod(add);
    }
    while(quatro.size()){
        string add = quatro.front();
        quatro.pop();
        sum += stod(add);
    }
    cout << sum << endl;
}