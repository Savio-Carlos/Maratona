#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define int long long
#define ld long double

void dbg_out() { cerr << endl; }
template<typename H, typename... T> 
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }

// #define DEBUG

#if defined(DEBUG)
    #define winton (void)0
    #define debug(...) cerr << BOLD_BLUE << "[" << __func__ << ":" << __LINE__ << "]" << RESET << " "; debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
    #define winton ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
    #define debug(...) (void)0
#endif

signed main(){
    winton;
    string s, t;
    cin >> s >> t;
    int n = s.size();
    vector<int> a(n);
    for (auto &u : a) cin >> u;

    int l = 0, r = n-1;
    int ans = 0;
    while (l <= r){
        int mid = (l + r) / 2;

        unordered_set<int> removidos;
        removidos.reserve(mid);
        for (int i = 0; i < mid; i++) removidos.insert(a[i]-1);
        
        int b = 0;
        bool pos = false;
        for (int i = 0; i < n; i++){
            if (removidos.count(i)) continue;
            if (s[i] == t[b]){
                b++;
            }
            if (b == t.size()){
                pos = true;
                break;
            }
        }
        if (pos){
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << ans << endl;
}