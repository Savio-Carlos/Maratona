#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define int long long
#define ld long double
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

signed main(){
    fastio;
    int n; cin >> n;
    vector<string> animal(n);
    vector<int> influence(n);
    int maior=LLONG_MIN;
    for(int i=0;i<n;i++){
        cin >> animal[i] >> influence[i];
        if(animal[i] == "pig"){
            maior=max(maior,influence[i]);
        }
    }
    int ans=maior;
    for(int i=0;i<n;i++){
        if(animal[i] != "pig" && influence[i] < maior){
            ans+=influence[i];
        }
    }
    cout << ans << endl;

}