#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

struct segtree{
    vector<int> v;
    int size;
    void init(int n){
        int i = 1;
        while(i < n) i *= 2;
        v.assign(i, 0);
    }

    void build(vector<int> v){
        
    }

};

signed main(){
    fastio;
    int n;
    cin >> n;
    map<int,int> mp;
    set<int> direita, esquerda;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        mp[v[i]] = i;
    }
    for(int i = 0; i < n; i++){
        direita.insert(v[i]);
    }
    int ans = 0;
    for(int i = 0; i < n; i++){

        direita.erase(v[i]);

        auto dir = direita.upper_bound(v[i]), esq = esquerda.upper_bound(v[i]);

        if(dir != direita.end() && esq != esquerda.end()){
            int val1 = *dir, val2 = *esq;
            ans += min(abs(i - mp[*dir]), i - mp[*esq]);
            cout << min(abs(i - mp[*dir]), i - mp[*esq]) << endl;
        }
        else if (dir != direita.end()){
            int val = *dir;
            ans += abs(mp[*dir] - i);
            cout << abs(mp[*dir] - i) << endl;
        } else if (esq != esquerda.end()){
            int val = *esq;
            ans += abs(mp[*esq] - i);
            cout << abs(mp[*esq] - i) << endl;
        }

        esquerda.insert(v[i]);
        // cout << ans << endl;
        
    }
    cout << ans << endl;
}

// 5
// 7 3 2 100 1
// 6
// 8
// 45 13 18 10 8 56 17 19
// 13