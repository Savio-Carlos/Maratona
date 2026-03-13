#include <bits/stdc++.h>
using namespace std;


#define int long long
#define ld long double
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)

signed main(){
    fastio;
    int q;
    cin >> q;
    while(q--){
        int ll, rr;
        cin >> ll >> rr;
        int l = 0, r = 1e6+7;
        int ansl= 0, ansr=0;;
        while (l <= r){
            int mid = l + (r-l)/2;
            int cur = mid*(mid+1)*(mid+2);
            if (cur >= ll){
                ansl = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        // cout << "ansl: " << ansl << endl;

        l = 0, r = 1e6+7;
        while (l <= r){
            int mid = l + (r-l)/2;
            int cur = mid*(mid+1)*(mid+2);
            if (cur <= rr){
                ansr = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
        // cout << "ansr: " << ansr << endl;
        cout << ansr - ansl + 1 << endl;
    }

}