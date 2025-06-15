#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
#define debug(x) cout << #x << " = " << x << "\n";
const int MAX = 3e5+7;
const int INF = INT_MAX;

int mp[MAX];

signed main(){
    winton;
    int n, l;
    cin >> n >> l;
    if (l%3 != 0){
        cout << 0 << endl;
        return 0;
    }
    mp[0]++;
    int prev = 0;
    for (int i = 0; i < n-1; i++){
        int d;
        cin >> d;
        int place = (prev + d)%l;
        //debug(place);
        mp[place]++;
        prev = place;
    }
    int side = l/3;
    int ans = 0;
    for(int i = 0; i < l/3; i++){
        if (mp[i] > 0 && mp[i+side] > 0 && mp[i+2*side] > 0){
            int a = mp[i];
            int b = mp[i+side];
            int c = mp[i+2*side];
            // debug(a);
            // debug(b);
            // debug(c);
            // cout << i << " - " << i+side << " - " << i+side*2 << endl;
            ans += a*b*c;
        }
    }
    cout << ans << endl;
}