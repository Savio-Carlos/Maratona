#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
const int MAX = 2e4+7;
const int MOD = 1e9+7;

set<int> enes;
vector<int> powers;

bool isSubsetSum(int sum) {
    int n = powers.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;
    for (int i = 1; i <= n; i++) {
      
        for (int j = 1; j <= sum; j++) {
            if (j < powers[i - 1]) {
                dp[i][j] = dp[i - 1][j]; 
            }
            else {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - powers[i - 1]];
            }
        }
    }
    return dp[n][sum];
}

void gerarn(string s, int idx){
    for (int i = idx; i < s.size(); i++){
        if (s[i] == '*'){
            s[i] = '1';
            gerarn(s,i);
            s[i] = '0';
            gerarn(s,i);
        }
    }
    if (idx == s.size()-1){
        int num = 0;
        for (int i = 0; i < s.size(); i++){
            num |= ((s[i] - '0') << i);
        }
        if (num) enes.insert(num);
    }
}

signed main(){
    winton;
    string m, n;
    cin >> m >> n;
    int lenM = m.size(); 
    //int lenN = n.size();
    gerarn(n,0);
    if (enes.empty()){
        int num = 0;
        for (int i = 0; i < n.size(); i++){
            num |= ((n[i] - '0') << i);
        }
        if (num) enes.insert(num);
    }


    string s = m;
    for (int i = 0; i < lenM; i++){
        if (s[i] == '*') s[i] = '0';
        powers.push_back((1<<(lenM-i-1)));
    }

    for (auto u : enes) { //para esse valor do divisor N e possivel fazer um M divisivel?
        cout << u << endl;
        int resto = 0;
        for (char c : s) {
            resto = (resto * 2 + (c - '0')) % u;
        }
        debug(resto);
        int alvo = (u-resto) % u;
        //dado todos os asteriscos em M, quero saber se consigo arrumar eles de maneira que o valor no numero fique alvo
        //cada asterisco contribui com 1<<i na soma
        if (isSubsetSum(alvo)){
            //reconstruir a string M
        }
    }
}

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string m, n;
    cin >> m >> n;

    vector<pair<int, int>> wilds;

    for (int i = 0; i < m.size(); i++) {
        if (m[i] == '*') {
            wilds.push_back({0, i});
        }
    }
    for (int i = 0; i < n.size(); i++) {
        if (n[i] == '*') {
            wilds.push_back({1, i});
        }
    }

    int total_wild = wilds.size();

    for (int mask = 0; mask < (1 << total_wild); mask++) {
        string m1 = m;
        string n1 = n;

        for (int i = 0; i < total_wild; i++) {
            int bit = (mask >> i) & 1;
            char ch = '0' + bit;
            if (wilds[i].first == 0) {
                m1[wilds[i].second] = ch;
            } else {
                n1[wilds[i].second] = ch;
            }
        }

        long long N_value = 0;
        for (char c : n1) {
            N_value = N_value * 2 + (c - '0');
        }

        if (N_value == 1) {
            cout << m1 << endl;
            return 0;
        }

        long long rem = 0;
        for (char c : m1) {
            rem = rem * 2 + (c - '0');
            if (rem >= N_value) {
                rem -= N_value;
            }
        }

        if (rem == 0) {
            cout << m1 << endl;
            return 0;
        }
    }

    for (char c : m) {
        if (c == '*') 
            cout << '0';
        else 
            cout << c;
    }
    cout << endl;

    return 0;
}