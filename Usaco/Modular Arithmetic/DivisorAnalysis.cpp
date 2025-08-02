        #include <bits/stdc++.h>
        using namespace std;
        #define ld long double
        #define int long long
        #define all(x) x.begin(), x.end()
        #define rall(x) x.rbegin(), x.rend()
        #define endl '\n'
        #define winton ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)
        #define debug(x) cout << #x << " = " << x << "\n";
        #define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
        const int MAX = 1e6+7;
        const int MOD = 1e9+7;

        int fastExpo(int base, int exp) {
            int r = 1;
            base %= MOD;
            while(exp) {
                if (exp & 1) r = r * base % MOD;
                base = base * base % MOD;
                exp >>= 1;
            }
            return r;
        }

        int modinverse(int n) {
            return fastExpo(n, MOD - 2);
        }

        int modiv(int a, int b){
            return (a * modinverse(b))%MOD;
        }

        signed main(){
            winton;
            int n;
            cin >> n;
            bool par = true;
            vector<int> p(n), k(n);
            int cnt = 1, sum = 1, prod = 1, cnt2 = 1;
            for (int i = 0; i < n; i++){
                cin >> p[i] >> k[i];
                if (k[i]&1) par = false;
            }
            for (int i = 0; i < n; i++){          
                cnt = (cnt * (k[i]+1)) % MOD;
                cnt2 = (cnt2 * (k[i]+1)) % (2*(MOD-1));
                
                int exp = (k[i] % (MOD-1));
                exp = (exp+1) % (MOD-1);
                //debug(exp);
                int num = (fastExpo(p[i],exp)-1 + MOD) % MOD;
                int den = (p[i]-1 + MOD) % MOD;
                sum = (sum * modiv(num,den)%MOD)%MOD;
            }
            for (int i = 0; i < n; i++){       
                if (!par){
                    int half = (cnt2/2)%(MOD-1);
                    int exp = (k[i]*half)%(MOD-1);
                    prod = (prod * (fastExpo(p[i],exp)%MOD)) % MOD;
                }
                else{
                    int exp = ((k[i]/2)*cnt2)%(MOD-1);
                    prod = (prod * (fastExpo(p[i],exp)%MOD)) % MOD;
                }
            }
            cout << cnt%MOD << ' ' << sum%MOD << ' ' << prod%MOD << endl;
        }