// ==========================================
// TEMPLATE 1: RECURSIVA Padrão [0, R] ou [1, R]
// ==========================================
int dp[20][11][2][2]; // [index][state][tight][ldz]

int pd(int index, int state, int tight, int ldz) {
    if(index == n) {
        return /* condicao base */;
    }
    
    if (dp[index][state][tight][ldz] != -1) return dp[index][state][tight][ldz];

    int ub = tight ? r[index] - '0' : 9;
    int ans = 0;

    for (int digit = 0; digit <= ub; digit++) {
        // if(!ldz && condicao_invalida) continue;

        int new_tight = tight && (digit == ub);
        int new_ldz = ldz && (digit == 0);
        
        int new_state = state; // atualiza seu estado

        ans += pd(index + 1, new_state, new_tight, new_ldz);
    }
    return dp[index][state][tight][ldz] = ans; 
}

// ==========================================
// TEMPLATE 2: RECURSIVA Range [L, R] Simultâneo
// ==========================================
int dp[20][11][2][2][2]; // [index][state][above][under][ldz]

int pd(int index, int state, int above, int under, int ldz) {
    if(index == n) return /* condicao base */;

    if (dp[index][state][above][under][ldz] != -1) return dp[index][state][above][under][ldz];

    int ub = above ? r[index] - '0' : 9;
    int lb = under ? l[index] - '0' : 0;
    int ans = 0;

    for (int digit = lb; digit <= ub; digit++) {
        // if(!ldz && condicao_invalida) continue;

        int new_above = above && (digit == ub);
        int new_under = under && (digit == lb);
        int new_ldz = ldz && (digit == 0);
        
        int new_state = state; // atualiza seu estado

        ans += pd(index + 1, new_state, new_above, new_under, new_ldz);
    }
    return dp[index][state][above][under][ldz] = ans; 
}

// ==========================================
// TEMPLATE 3: ITERATIVA PUSH DP
// ==========================================
void solve_iterative() {
    int dp[20][11][2][2]; // [index][last][tight][ldz]
    memset(dp, 0, sizeof(dp));

    dp[0][10][1][1] = 1;

    for (int index = 0; index < n; index++) {
        for (int last = 0; last <= 10; last++) {
            for (int tight = 0; tight < 2; tight++) {
                for (int ldz = 0; ldz < 2; ldz++) {
                    
                    int ways = dp[index][last][tight][ldz];
                    if(!ways) continue;

                    int limit = tight ? r[index] - '0' : 9;
                    
                    for (int digit = 0; digit <= limit; digit++) {
                        
                        if(!ldz && last == digit) continue;

                        int new_tight = tight && (digit == limit);
                        int new_ldz = ldz && (digit == 0);
                        
                        int next = new_ldz ? 10 : digit;

                        dp[index+1][next][new_tight][new_ldz] += ways;
                    }
                }
            }
        }
    }
}


int pd(int index, int sum, int above, int under){
    if(index == n) return (sum == 0);

    if (!above && !under && dp[index][sum] != -1) return dp[index][sum];

    int ub = above ? r[index] - '0' : 9;
    int lb = under ? l[index] - '0' : 0;
    int ans = 0;

    for (int digit = lb; digit <= ub; digit++){

        int new_above = above && (digit == ub);
        int new_under = under && (digit == lb);
        
        int new_sum = (sum * 10 + digit) % M;
        
        ans = (ans + pd(index + 1, new_sum, new_above, new_under)) % MOD;
    }
    
    if (!above && !under) dp[index][sum] = ans; 
    return ans;
}


//so precisa fazer memset uma vez mas dai precisa fazer padding pra ambos os numeros terem o mesmo numero de digitos
int count(int x){
    s = to_string(x);
    
    int pad = 19 - s.size();
    if (pad > 0) s = string(pad, '0') + s;
    
    n = s.size();
    return pd(0,0,1);
}

void solve(){
    int l, r;
    cin >> l >> r;
    memset(dp, -1, sizeof(dp));
    cout << count(r) - count(l-1) << endl;
}

/*
otimizacao super importante
desse jeito, o digito menos significativo sempre esta na posicao 0
entao as posicoes dos digitos de cada numero sempre estarao na mesma posicao
por exemplo 1234 e 12
do jeito normal ficaria 
1234
  12

desse jeito fica
4321
  21

entao a potencia de 10 em cada posicao e sempre a mesma, permitindo so rodar o memset uma vez 
*/
vector<int> v; 
int pd(int index, int tight, int mask, int ldz){
    if (index == -1) return ((__bit_width(mask) - 1) == __popcount(mask));
    
    if (!tight && dp[index][mask][ldz] != -1) return dp[index][mask][ldz];

    int ub = tight ? v[index] : 9;
    int ans = 0;
    int sum = 0;

    for (int digit = 0; digit <= ub; digit++){
        int new_tight = tight && (digit == ub);

        int new_ldz = ldz && (digit == 0);
        
        int new_mask = mask;
        if (!new_ldz) new_mask |= (1 << digit);

        ans += pd(index - 1, new_tight, new_mask, new_ldz);
    }

    if (!tight) dp[index][mask][ldz] = ans; 
    return ans;
}

int count(ll x){
    v.clear();
    while(x) {
        v.push_back(x % 10);
        x /= 10;
    }

        /* [L,R]
    int count(int x, int y){
    v2.clear();
    while(x) {
        v2.push_back(x % 10);
        x /= 10;
    }
    v.clear();

    while(y) {
        v.push_back(y % 10);
        y /= 10;
    }
    while(v2.size() < v.size()) v2.push_back(0LL);
    */
   
    n = v.size();
    return pd(n-1,1,0,1);
}

void solve(){
    ll r;
    cin >> r;
    cout << count(r) << endl;
}

signed main(){
    winton;
    memset(dp, -1, sizeof(dp));
    int t;
    cin >> t;
    while(t--) solve();
}
