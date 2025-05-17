#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
const int MOD = 1e8;
const int MAXN = 1e2+7;
const int MAXM = 1e4+7;

signed main(){  
    winton;
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;
    int k, l;
    cin >> k >> l;

    vector<int> pfx(n + 1, 0), sfx(n + 1, 0);
    for (int i = 1; i <= n; i++){
        pfx[i] = a[i-1] + pfx[i-1];
        sfx[i] = a[n-i] + sfx[i-1];
    }

    multiset<int> virado, virado2;
    int sum = 0;
    for (int i = 0; i < k; i++){
        if (virado.size() < l) {
            virado.insert(b[i]);
            sum+=b[i];
        }
        else{
            if (b[i] > *virado.begin()){
                virado2.insert(*virado.begin());
                sum-= *virado.begin();
                sum+=b[i];
                virado.erase(virado.begin());
                virado.insert(b[i]);
            }
            else {
                virado2.insert(b[i]);
            }
        }
    }
    // cout << "virado1: ";
    // for (auto u : virado) cout << u << " ";
    // cout << endl<<"virado2: " ;
    // for (auto u : virado2) cout << u << " ";
    // cout << endl << endl;
    // cout << sum << endl;

    int ans = 0;

    for (int i = k; i >= 0; i--){
        if (i < k){
            if (virado.find(b[i]) != virado.end()){
               virado.erase(virado.find(b[i]));
                sum -= b[i];
                auto it = prev(virado2.end());
                virado.insert(*it);
                sum += *it;
                virado2.erase(it);
            }           
            else virado2.erase(virado2.find(b[i]));

            if (virado.size() < l) {
                virado.insert(b[n-(k-i)]);
                sum += b[n-(k-i)];
            } 
            else {
                auto it = virado.begin();
                if (b[n-(k-i)] > *it) {
                    sum -= *it;
                    virado2.insert(*it);
                    virado.erase(it);
                    virado.insert(b[n-(k-i)]);
                    sum += b[n-(k-i)];
                } 
                else {
                    virado2.insert(b[n-(k-i)]);
                }
            }
        }
        // cout << i << " " << k-i << endl;
        // cout << "virado1: ";
        // for (auto u : virado) cout << u << " ";
        // cout << endl<<"virado2: " ;
        // for (auto u : virado2) cout << u << " ";
        // cout<<endl << "pfx[i] = " << pfx[i] << " sum = " << sum << " sfx[k-i] = " << sfx[k-i] << endl;

        int cur = pfx[i] + sum + sfx[k-i];
        
        // cout <<cur << endl << endl;

        ans = max(cur,ans);

    }
    cout << ans << endl;
}