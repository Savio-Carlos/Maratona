#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define ll long long
#define ld long double

#define debug(x)  cerr << #x << ": " << x << endl
#define debugv(x) cerr << #x << ": "; for(auto i : x) cerr << i << " "; cerr << endl
#define debugp(x) cerr << #x << ": " << x.first << " " << x.second << endl

#define winton ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

signed main(){
    winton;
    int n, q;
    cin >> n >> q;
    vector<int> top(n+1);
    ordered_set blocks;
    int aux = 0;
    
    for (int i = 1; i <= n; i++) blocks.insert({0, i});

    while(q--){
        int t;
        cin >> t;
        if (t == 1){
            int x;
            cin >> x;

            blocks.erase({top[x], x});
            top[x]++;
            blocks.insert({top[x], x});
            
            while (blocks.find_by_order(0)->first == aux + 1) aux++;
        }
        else {
            int y;
            cin >> y;
            int ans = n - blocks.order_of_key({y+aux, -1});
            cout << ans << endl;
        }
    }
}