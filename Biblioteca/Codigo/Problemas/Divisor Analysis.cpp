//Divisor Analysis

// quantidade, soma e produto dos divisores

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