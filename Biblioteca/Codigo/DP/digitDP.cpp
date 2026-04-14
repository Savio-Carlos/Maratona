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