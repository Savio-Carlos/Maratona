#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define int long long
#define ld long double
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)


int nxt(){
    int x; cin >> x;
    return x;
}

signed main(){
    fastio;
    int n;
	cin >> n;
    vector<int> v(n);
    generate(all(v),nxt);

    vector<int> pfx(n+1);
    for(int i=1;i<=n;i++){
        pfx[i] = 2*v[i-1]+pfx[i-1];
    }

    for(int i=0;i<n;i++){
        v[i]=abs(v[i]);
    }

    vector<int>pfx2(n+1);
    for(int i=1;i<=n;i++){
        pfx2[i] = v[i-1]+pfx2[i-1];
    }

    int max_sum = pfx[1];
    int min_sum = pfx[0];
    int min_pos = 0;

    int ans = 0;
    for(int i=1;i<=n;i++){
        max_sum = max(max_sum,pfx[i] - pfx[min_pos] + pfx2[min_pos] + (pfx2[n] - pfx2[i]));
        if(pfx2[i] < min_sum){
            min_sum = pfx[i];
            min_pos = i;
        }
        // cout << min_pos << " " << min_sum << " " << max_sum << " " << pfx2[n] - pfx2[i] << endl;
    }
    cout << max(max_sum,pfx2[n]) << endl;

    return 0;
}