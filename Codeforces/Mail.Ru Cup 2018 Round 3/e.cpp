#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define int long long
#define ld long double

namespace dbg {
    const char* const RESET     = "\033[0m";
    const char* const BOLD_BLUE = "\033[1;34m";
    const char* const YELLOW    = "\033[33m";
    const char* const BOLD_WHITE= "\033[1;37m";

    template<typename T1, typename T2>
    ostream& operator<<(ostream& os, const pair<T1, T2>& p) { return os << '{' << p.first << ", " << p.second << '}'; }

    template<typename T_container, typename T = typename enable_if<!is_same_v<T_container, string> && !is_same_v<T_container, string_view>, typename T_container::value_type>::type>
    ostream& operator<<(ostream& os, const T_container& v) {
        os << '{';
        bool first = true;
        for (const T& x : v) { os << (first ? "" : ", ") << x, first = false; }
        return os << '}';
    }

    void debug_out(string_view) { cerr << endl; }
    template<typename H, typename... T>
    void debug_out(string_view s, H h, T... t) {
        auto cpos = s.find(',');
        cerr << YELLOW << s.substr(0, cpos) << RESET << " = ";
        cerr << BOLD_WHITE << h << RESET;
        if constexpr (sizeof...(t) > 0) {
            cerr << ", ";
            auto nx = s.find_first_not_of(" \t\n\r", cpos + 1);
            debug_out(s.substr(nx), t...);
        } else {
            cerr << endl;
        }
    }
} 
using namespace dbg;

// #define DEBUG

#if defined(DEBUG)
    #define winton (void)0
    #define debug(...) cerr << BOLD_BLUE << "[" << __func__ << ":" << __LINE__ << "]" << RESET << " "; debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
    #define winton ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
    #define debug(...) (void)0
#endif

const int P = 31; 
const int MOD = 972663749;

signed main(){
    winton;
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    if (n > m) {
        cout << 0 << endl;
        return 0;
    }

    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < n; i++){
        if (s[i] == '1') cnt1++;
        else cnt0++;
    }

    int mx0 = (m - cnt1) / cnt0;
    debug(mx0); 

    vector<int> p_pow(m); 
    p_pow[0] = 1; 
    for (int i = 1; i < (int)p_pow.size(); i++) p_pow[i] = (p_pow[i-1] * P) % MOD;
    
    vector<int> h(m + 1, 0); 
    for (int i = 0; i < m; i++) h[i+1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % MOD;
    
    vector<int> ans;

    debug(p_pow, h);

    for (int i = 1; i <= mx0; i++){

        int h0 = -1, h1 = -1;
        if ((m - (cnt0 * i)) % cnt1 != 0) continue;
        int r1sz = (m - (cnt0 * i)) / cnt1;//se nao der inteiro eu posso dar continue eu acho 
        if (r1sz == 0) continue;
        // debug(r1sz);
        if (cnt0*i + cnt1*r1sz != m) continue;
        int r1cnt = 0, r0cnt = 0;
        
        int idx0 = -1, idx1 = -1;

        debug(i);
        bool valid = true;

        for (int j = 0; j < n; j++){
            int idx = (r0cnt * i) + (r1cnt * r1sz);
            if (idx > m) continue;
            // debug(i, j, idx);
            if (s[j] == '0'){
                if (idx + i > m){
                    valid = false;
                    break;
                }

                // debug(idx+i, f);
                if (h0 == -1){
                    //hash de 0 ainda nao definido, pego o hash que comeca em (j)*i+qtd1 e tem tamanho i
                    h0 = (h[idx+i] + MOD - h[idx]) % MOD;
                    idx0 = idx;
                    if (h1 != -1 && (h0 * p_pow[idx1]) % MOD == (h1 * p_pow[idx0]) % MOD) valid = false;
                    debug(h0);
                }
                else {
                    int curh =  (h[idx+i] + MOD - h[idx]) % MOD;
                    if ((curh * p_pow[idx0]) % MOD != (h0 * p_pow[idx]) % MOD){
                        // cout << "aqui\n";

                        valid = false;
                    } 
                    // debug(curh, h0 * p_pow[idx] % MOD);
                }
                r0cnt++;    
            }
            else if (s[j] == '1'){
                debug(idx+r1sz);
                if (idx + r1sz > m) {
                    valid = false;
                    break;
                }
                if (h1 == -1){
                    h1 = (h[idx+r1sz] + MOD - h[idx]) % MOD;
                    idx1 = idx;
                    if (h0 != -1 && (h1 * p_pow[idx0]) % MOD == (h0 * p_pow[idx1]) % MOD) valid = false;
                    debug(h1, h0, idx);
                }
                else {
                    int curh = (h[idx+r1sz] + MOD - h[idx]) % MOD;
                    if ((curh * p_pow[idx1]) % MOD != (h1 * p_pow[idx]) % MOD) valid = false;
                    // debug(curh, h1 * p_pow[idx] % MOD);
                }
                r1cnt++;
            }
        }
        if (valid) ans.push_back(i);
    }
    debug(ans);
    cout << ans.size() << endl;
}