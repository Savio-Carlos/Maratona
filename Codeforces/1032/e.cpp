#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define debug(x) cout << #x << " = " << x << "\n";
#include <chrono>
const int MAX = 2e5+7;
const int INF = INT_MAX;

int potenciade10(int x){
    int ans = 1;
    while(x--)ans*=10;
    return ans;
}

bool compara(int a, int b){
    string s = to_string(a);
    string t = to_string(b);
    return (s.size() < t.size());
}

void solve(){
    string s, t;
    cin >> s >> t;
    int n = s.size(), ans = n*2, f = 0, sn = stoi(s), tn = stoi(t);
    int diference = tn-sn;
    int k = 0;
    for (int i = 0; i < n; i++){
        int a = t[i] - '0', b = s[i] - '0';
        if (a < b) a+=10;
        int diff = a-b;
        int x = potenciade10(n-i-1);
        if (diff > 1){
            f = n-i;
            break;
        }
        if (k && (x*9 <= diference)){
            f = n-i;
            break;
        }
        else if (compara(x,diference)){
            f = n-i;
            break;
        }
        if (diff == 1){
            ans--;
            k = 1;
        }
    }
    cout << ans - f*2 << endl;
}

signed main(){
    winton;
    auto start = chrono::high_resolution_clock::now();
    int t;
    cin >> t;
    while(t--) solve();
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    cout << "Tempo de execução: " << elapsed.count() << " segundos." << endl;
}