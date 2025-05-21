#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MAXN = 1e6+7;

signed main(){
    winton;
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &u : a) cin >> u;
    vector<int> pilha;
    for (int cur : a){
        int pos = upper_bound(pilha.begin(), pilha.end(), cur) - pilha.begin();
        if (pos == pilha.size()){
            pilha.push_back(cur);
        }
        else {
            pilha[pos] = cur;
        }
    }
    cout << pilha.size() << endl;
}
