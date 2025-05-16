#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long
const int MAXL = 1e9+7;

void setIO(string name = "") {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

signed main() {
	setIO("angry");
    int n; cin >> n;
    vector<int> hay (n);
    for (int &i:hay) cin >> i;
    sort(all(hay));
    int ans = 0;
    for (int i = 0; i < n; i++){
        int blastRadius = 1;
        int l = i-1, r = i+1;
        int exploded = 1;
        int prev = i;
        while (l >= 0){
            if (hay[prev] - hay[l] <= blastRadius){
                while (hay[prev] - hay[l] <= blastRadius && l >= 0){
                    l--;
                    exploded++;
                }
                blastRadius++;
                prev = l+1;
            }
            else break;
        }
        prev = i;
        blastRadius = 1;
        while (r < n){
            if (hay[r] - hay[prev] <= blastRadius){
                while (hay[r] - hay[prev] <= blastRadius && r < n){
                    r++;
                    exploded++;
                }
                blastRadius++;
                prev = r-1;
            }
            else break;
        }
        
        //cout << exploded << " explodidos na posicao inicial i: " << i << endl;
        ans = max (ans,exploded);
    }
    cout << ans << endl;
}   