vector<int> rabin_karp(string const& s, string const& t) {
    int S = s.size(), T = t.size();
        
    vector<int> p_pow(max(S, T)); 
    p_pow[0] = 1; 
    for (int i = 1; i < (int)p_pow.size(); i++) p_pow[i] = (p_pow[i-1] * P) % MOD;
    
    vector<int> h(T + 1, 0); 
    for (int i = 0; i < T; i++) h[i+1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % MOD; //hash do texto(vetor a)
    
    int h_s = 0; 
    for (int i = 0; i < S; i++) h_s = (h_s + (s[i]- 'a' + 1) * p_pow[i]) % MOD; //hash da string s (vetor b)
    
    vector<int> occurrences;
    for (int i = 0; i + S - 1 < T; i++) {
        int cur_h = (h[i+S] + MOD - h[i]) % MOD;
        if (cur_h == h_s * p_pow[i] % MOD) occurrences.push_back(i);
    }
    return occurrences;
}