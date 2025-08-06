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
const int MAX = 2e5+7;
const int MOD = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); 
    int T; cin >> T;
    for(int test = 1; test <= T; test++) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        ll sum = 0;
        for(ll i : a) {
            sum += i;
        }
        if(sum % 2) {
            cout << "-1\n";
            continue;
        }
        ll mx = 0;
        for(ll i : a) {
            mx = max(mx, i);
        }
        if(mx * 2 > sum) {
            cout << "-1\n";
            continue;
        }
        ll cur = 0; int ind = 0;
        for(; ind < n; ind++) {
            if(cur + a[ind] > sum / 2) {
                ind--;
                break;
            }
            cur += a[ind];
        }
        if(cur == sum / 2) {
            cout << "1\n";
            for(ll i : a) {
                cout << i << " ";
            }
            cout << "\n";
        } else {
            cout << "2\n";
            vector<ll> aa(n);
            ll extra = sum - 2 * cur;
            debug(extra);
            debug(cur);
            aa[ind + 1] = extra / 2;
            a[ind + 1] -= aa[ind + 1];
            extra /= 2;
            for(int i = n - 1; i > ind + 1 && extra; i--) {
                if(a[i] >= extra) {
                    aa[i] = extra;
                    a[i] -= extra;
                    extra = 0;
                } else {
                    aa[i] = a[i];
                    extra -= a[i];
                    a[i] = 0;
                }
            }
            for(int i = 0; i < n; i++) {
                cout << a[i] << " ";
            }
            cout << "\n";
            for(int i = 0; i < n; i++) {
                cout << aa[i] << " ";
            }
            cout << "\n";
        }
    }
}